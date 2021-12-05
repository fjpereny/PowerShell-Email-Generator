Add-Type -assembly "Microsoft.Office.Interop.Outlook"
$Outlook = New-Object -comobject Outlook.Application
$Mail = $Outlook.CreateItem(0)
$Mail.To = "frank.pereny@sullair.com"
$Mail.Cc = "amit.godbole@sullair.com"
$Mail.Bcc = ""
$Mail.Subject = "DS 45-75kW - PPAP Documents - Frank Pereny - DUE 12-1-21 - STATUS: Late"
$Mail.Body = "Dear Frank Pereny,
You have been assigned the following task.  Please confirm your estimated completion date as soon as possible.

Task: PPAP Documents
Status: Late
Due Date: 12-1-21
Project Name: DS 45-75kW
Project Gate: Launch Readiness
Gate Due Date: 12-1-21

For your convenience, the following documents have been attached to this email:
 - NPD Gate Deliverable List
 - Program PDS
 - Latest Monthly PMO Review Slides
 - Current NPD Program Dashboard

 In the event the activity becomes past due, it will automatically be escalated and assigned to the following manager:

Admit Godbole
amit.godbole@sullair.com

Thanks for your continued support,
Sullair Program Management
"
$files = Get-ChildItem -Path "c:/" -File
foreach($file in $files)
{
$Mail.Attachments.Add("c:/" + $file)
}
$Mail.Send()

$Mail = $Outlook.CreateItem(0)
$Mail.To = "frank.pereny@sullair.com"
$Mail.Cc = "amit.godbole@sullair.com"
$Mail.Bcc = ""
$Mail.Subject = "DS 45-75kW - DVPR Review - Frank Pereny - DUE 12-31-21 - STATUS: Incomplete"
$Mail.Body = "Dear Frank Pereny,
You have been assigned the following task.  Please confirm your estimated completion date as soon as possible.

Task: DVPR Review
Status: Incomplete
Due Date: 12-31-21
Project Name: DS 45-75kW
Project Gate: Launch Readiness
Gate Due Date: 12-1-21

For your convenience, the following documents have been attached to this email:
 - NPD Gate Deliverable List
 - Program PDS
 - Latest Monthly PMO Review Slides
 - Current NPD Program Dashboard

 In the event the activity becomes past due, it will automatically be escalated and assigned to the following manager:

Amit Godbole
amit.godbole@sullair.com

Thanks for your continued support,
Sullair Program Management
"
$files = Get-ChildItem -Path "c:/" -File
foreach($file in $files)
{
$Mail.Attachments.Add("c:/" + $file)
}
$Mail.Send()

$Mail = $Outlook.CreateItem(0)
$Mail.To = "frank.pereny@sullair.com"
$Mail.Cc = "amit.godbole@sullair.com"
$Mail.Bcc = ""
$Mail.Subject = "DS 45-75kW - Gate Signoff - Frank Pereny - DUE 12-31-21 - STATUS: Incomplete"
$Mail.Body = "Dear Frank Pereny,
You have been assigned the following task.  Please confirm your estimated completion date as soon as possible.

Task: Gate Signoff
Status: Incomplete
Due Date: 12-31-21
Project Name: DS 45-75kW
Project Gate: Launch Readiness
Gate Due Date: 12-1-21

For your convenience, the following documents have been attached to this email:
 - NPD Gate Deliverable List
 - Program PDS
 - Latest Monthly PMO Review Slides
 - Current NPD Program Dashboard

 In the event the activity becomes past due, it will automatically be escalated and assigned to the following manager:

Amit Godbole
amit.godbole@sullair.com

Thanks for your continued support,
Sullair Program Management
"
$files = Get-ChildItem -Path "c:/" -File
foreach($file in $files)
{
$Mail.Attachments.Add("c:/" + $file)
}
$Mail.Send()

