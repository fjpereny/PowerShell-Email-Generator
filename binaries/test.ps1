# Made By PowerShell Email Generator
# --------------------------------------------------------------------------------------
# PowerShell Email Generator
# Copyright (C) 2021 Frank Pereny
# https://github.com/fjpereny/PowerShell-Email-Generator
#
# This program is free software: you can redistribute it and/or modify it under the
# terms of the GNU General Public License as published by the Free Software
# Foundation, either version 3 of the License, or (at your option) any later version.

# This program is distributed in the hope that it will be useful, but WITHOUT ANY
# WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
# FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
# --------------------------------------------------------------------------------------
#
# Program: DS45-75kW
# Created: Thursday, December 09, 2021

Add-Type -assembly "Microsoft.Office.Interop.Outlook"
$Outlook = New-Object -comobject Outlook.Application
# ------------ EMAIL BEGIN -----------------
$Mail = $Outlook.CreateItem(0)
$Mail.To = "smith.xiao@sullair.com"
$Mail.Cc = "tony.ju@sullair.com"
$Mail.Bcc = "fjpereny@gmail.com"
$Mail.Subject = "DS45-75kW Late PPAP Documents Received Nov-07-2020"
$Mail.Body = "Dear Smith Xiao,
Regarding the following NPD Program:
Program Name: DS45-75kW
Program Gate: LR
Program Date Plan Date: 3-1-21

You have been assigned the following task; please provide a daily update of the status to the cross-functional team.  A weekly report will be sent and reviewed by executive leadership.

Task: PPAP Documents Received
Status: Late
Due Date: Nov-07-2020

The program SharePoint is found at the following location.  Please ensure all deliverables are uploaded to the appropriate folder.  If you have difficulyt accessing the SharePoint site, please contact your program manager.

<SITE>

Past due tasks will be escalated and assigned to the following manager:

Tony Ju
tony.ju@sullair.com

Critically past due activities will be escalated and assigned to your department VP as required."
$Mail.Send()
# ------------ EMAIL END --------------------


# ------------ EMAIL BEGIN -----------------
$Mail = $Outlook.CreateItem(0)
$Mail.To = "colin.chen@sullair.com"
$Mail.Cc = "catherine.huang@sullair.com"
$Mail.Bcc = "fjpereny@gmail.com"
$Mail.Subject = "DS45-75kW Complete PPAP & FAI Finalized Dec-08-2020"
$Mail.Body = "Dear Colin Chen,
Regarding the following NPD Program:
Program Name: DS45-75kW
Program Gate: LR
Program Date Plan Date: 3-1-21

You have been assigned the following task; please provide a daily update of the status to the cross-functional team.  A weekly report will be sent and reviewed by executive leadership.

Task: PPAP & FAI Finalized
Status: Complete
Due Date: Dec-08-2020

The program SharePoint is found at the following location.  Please ensure all deliverables are uploaded to the appropriate folder.  If you have difficulyt accessing the SharePoint site, please contact your program manager.

<SITE>

Past due tasks will be escalated and assigned to the following manager:

Catherine Huang
catherine.huang@sullair.com

Critically past due activities will be escalated and assigned to your department VP as required."
$files = Get-ChildItem -Path "/home/frank/GitHub/PowerShell-Email-Generator/binaries/PowerShell-Email-Generator_autogen/EWIEGA46WW/" -File
foreach($file in $files)
{
$Mail.Attachments.Add("/home/frank/GitHub/PowerShell-Email-Generator/binaries/PowerShell-Email-Generator_autogen/EWIEGA46WW/" + $file)
}
$Mail.Send()
# ------------ EMAIL END --------------------


