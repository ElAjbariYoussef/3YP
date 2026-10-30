const express = require("express");
const http = require("http");
const { Server } = require("socket.io");

const app = express();
const server = http.createServer(app);
const io = new Server(server);

app.use(express.json());
app.use(express.static("public", { index: "dashboard.html" }));

const HISTORY_SIZE = 10;

let lastMeasurement = null;
let history = [];

function validateMeasurement(data) {
  const errors = [];

  if (data === null || typeof data !== "object" || Array.isArray(data)) {
    return ["Le corps de la requete doit etre un objet JSON"];
  }

  if (typeof data.device_id !== "string" || data.device_id.trim() === "") {
    errors.push("device_id est obligatoire et doit etre une chaine de caracteres");
  }

  if (typeof data.temperature !== "number" || !Number.isFinite(data.temperature)) {
    errors.push("temperature doit etre un nombre");
  } else if (data.temperature < -40 || data.temperature > 80) {
    errors.push("temperature doit etre comprise entre -40 et 80 degres");
  }

  if (typeof data.humidity !== "number" || !Number.isFinite(data.humidity)) {
    errors.push("humidity doit etre un nombre");
  } else if (data.humidity < 0 || data.humidity > 100) {
    errors.push("humidity doit etre comprise entre 0 et 100 %");
  }

  if (data.location !== undefined && typeof data.location !== "string") {
    errors.push("location doit etre une chaine de caracteres");
  }

  if (data.sensor_type !== undefined && typeof data.sensor_type !== "string") {
    errors.push("sensor_type doit etre une chaine de caracteres");
  }

  if (
    data.counter !== undefined &&
    (!Number.isInteger(data.counter) || data.counter < 0)
  ) {
    errors.push("counter doit etre un entier positif ou nul");
  }

  if (data.status !== undefined && typeof data.status !== "string") {
    errors.push("status doit etre une chaine de caracteres");
  }

  return errors;
}

app.post("/api/measurements", (req, res) => {
  const errors = validateMeasurement(req.body);

  if (errors.length > 0) {
    return res.status(400).json({
      success: false,
      message: "Donnees invalides",
      errors
    });
  }

  const data = req.body;

  const measurement = {
    device_id: data.device_id.trim(),
    temperature: data.temperature,
    humidity: data.humidity,
    location:
      typeof data.location === "string" && data.location.trim() !== ""
        ? data.location.trim()
        : "Salle inconnue",
    sensor_type:
      typeof data.sensor_type === "string" && data.sensor_type.trim() !== ""
        ? data.sensor_type.trim()
        : "DHT22",
    counter: data.counter !== undefined ? data.counter : null,
    status:
      typeof data.status === "string" && data.status.trim() !== ""
        ? data.status.trim()
        : "ACTIVE",
    receivedAt: new Date().toISOString()
  };

  lastMeasurement = measurement;

  history.unshift(measurement);
  if (history.length > HISTORY_SIZE) {
    history.pop();
  }

  console.log("Mesure recue :", measurement);

  io.emit("newMeasurement", measurement);
  io.emit("history", history);

  res.status(200).json({
    success: true,
    message: "Mesure recue",
    counter: measurement.counter
  });
});

app.get("/api/measurements/latest", (req, res) => {
  res.json(lastMeasurement);
});

app.get("/api/measurements/history", (req, res) => {
  res.json(history);
});

io.on("connection", (socket) => {
  console.log("Dashboard connecte :", socket.id);

  if (lastMeasurement) {
    socket.emit("newMeasurement", lastMeasurement);
  }

  socket.emit("history", history);

  socket.on("disconnect", () => {
    console.log("Dashboard deconnecte :", socket.id);
  });
});

server.listen(3000, "0.0.0.0", () => {
  console.log("Serveur actif sur http://0.0.0.0:3000");
});
