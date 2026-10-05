# Dynamic UML Study – Activity and Sequence Diagrams (Medical Clinic)

We are interested in the detailed process of **“Online Appointment Booking”** by a patient in the CliniqueSys system.
The process takes place as follows:
- The patient logs into their account. If they do not have an account, the system asks them to create one before continuing.
- Once logged in, the patient selects the desired medical specialty.
- The system displays the available time slots for doctors in that specialty.
- The patient selects a time slot.
- The system temporarily reserves the selected time slot (for 5 minutes) and asks the patient to confirm.
- Two actions are triggered in parallel: the system sends a verification code via SMS to the patient, and the patient enters the reason for their consultation.
- Once both actions are completed, the patient enters the verification code.
- If the code is incorrect, the time slot is released and the process stops (failure).
- If the code is correct, the appointment is confirmed, saved in the database, and a confirmation email is sent.
