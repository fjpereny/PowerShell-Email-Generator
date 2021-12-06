Add-Type -assembly "Microsoft.Office.Interop.Outlook"
$Outlook = New-Object -comobject Outlook.Application
$Mail = $Outlook.CreateItem(0)
$Mail.To = "f@cut.grass"
$Mail.Cc = "bob@lawn.mower"
$Mail.Bcc = ""
$Mail.Subject = "Get Rich Quick - Cut Grass"
$Mail.Body = "Hey there, this meail is to remind you to do your tasks ASAP!

Frank
Cut Grass
12-15-21
Incomplete

If you don't do it ASAP, we are going to need to contact your boss!
Bob Tillman
bob@lawn.mower"
$files = Get-ChildItem -Path "/home/attachments/" -File
foreach($file in $files)
{
$Mail.Attachments.Add("/home/attachments/" + $file)
}
$Mail.Send()

$Mail = $Outlook.CreateItem(0)
$Mail.To = "a@coin.cushion"
$Mail.Cc = "abe@penny.coin"
$Mail.Bcc = ""
$Mail.Subject = "Get Rich Quick - Check Couch"
$Mail.Body = "Hey there, this meail is to remind you to do your tasks ASAP!

Anna
Check Couch
11-1-21
Late

If you don't do it ASAP, we are going to need to contact your boss!
Abe Lincoln
abe@penny.coin"
$files = Get-ChildItem -Path "/home/attachments/" -File
foreach($file in $files)
{
$Mail.Attachments.Add("/home/attachments/" + $file)
}
$Mail.Send()

