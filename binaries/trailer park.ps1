Add-Type -assembly "Microsoft.Office.Interop.Outlook"
$Outlook = New-Object -comobject Outlook.Application
$Mail = $Outlook.CreateItem(0)
$Mail.To = j@j.ca
$Mail.Cc = jh@sunny.vale
$Mail.Bcc = 
$Mail.Subject = "Trail Park Program - Get Money - Julian - DUE 11-1-21 - STATUS: Late"
Mail.Body = "	Dear Julian,
You have been assigned the following task.  Please confirm your estimated completion date as soon as possible.

Task: Get Money
Status: Late
Due Date: 11-1-21
Project Name: Trail Park Program
Project Gate: Launch
Gate Due Date: 12-1-21

For your convenience, the following documents have been attached to this email:

- [ATTACHMENTS]

 In the event the activity becomes past due, it will automatically be escalated and assigned to the following manager:

Jim Lahey
jh@sunny.vale

Thanks for your continued support,
Sullair Program Management
"
Mail.Send()
$Mail = $Outlook.CreateItem(0)
$Mail.To = r@r.ca
$Mail.Cc = j@j.ca
$Mail.Bcc = 
$Mail.Subject = "Trail Park Program - Steal Gas - Ricky - DUE 12-31-21 - STATUS: Incomplete"
Mail.Body = "	Dear Ricky,
You have been assigned the following task.  Please confirm your estimated completion date as soon as possible.

Task: Steal Gas
Status: Incomplete
Due Date: 12-31-21
Project Name: Trail Park Program
Project Gate: Launch
Gate Due Date: 12-1-21

For your convenience, the following documents have been attached to this email:

- [ATTACHMENTS]

 In the event the activity becomes past due, it will automatically be escalated and assigned to the following manager:

Julian
j@j.ca

Thanks for your continued support,
Sullair Program Management
"
Mail.Send()
$Mail = $Outlook.CreateItem(0)
$Mail.To = b@b.ca
$Mail.Cc = jh2sunny.vale
$Mail.Bcc = 
$Mail.Subject = "Trail Park Program - Feed Cats - Bubbles - DUE 10-1-21 - STATUS: Complete"
Mail.Body = "	Dear Bubbles,
You have been assigned the following task.  Please confirm your estimated completion date as soon as possible.

Task: Feed Cats
Status: Complete
Due Date: 10-1-21
Project Name: Trail Park Program
Project Gate: Launch
Gate Due Date: 12-1-21

For your convenience, the following documents have been attached to this email:

- [ATTACHMENTS]

 In the event the activity becomes past due, it will automatically be escalated and assigned to the following manager:

Jim Lahey
jh2sunny.vale

Thanks for your continued support,
Sullair Program Management
"
Mail.Send()
