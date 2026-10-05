# UML Dynamic Study – Sequence Diagram (Medical Clinic)

We want to model the nominal scenario (successful case) of paying for a consultation by

bank card at the reception desk.
- The receptionist initiates the payment request by entering the patient's file number in the "CliniqueSys" interface.
- The "CliniqueSys" system retrieves the amount to be paid and displays it to the receptionist.
- The receptionist confirms the amount and asks the patient to insert their card into the Electronic Payment Terminal (POS terminal).
- The patient inserts their card and enters their PIN.
- The POS terminal sends an authorization request containing the PIN and the amount to the Banking System.
- The Banking System verifies the validity and returns an approval (authorization OK).
- The POS terminal validates the transaction and prints a receipt.
- The "CliniqueSys" system records the invoice as "Paid".
- The receptionist hands the receipt and the invoice to the patient.
