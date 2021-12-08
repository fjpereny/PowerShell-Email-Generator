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
# Created: Wednesday, December 08, 2021

Add-Type -assembly "Microsoft.Office.Interop.Outlook"
$Outlook = New-Object -comobject Outlook.Application
