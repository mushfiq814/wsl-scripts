# C# code
$code = @"
	public class Win32 {
		[DllImport("user32.dll")]
		public static extern bool GetWindowRect(IntPtr hWnd, out RECT lpRect);
	}

	public struct RECT {
		public int Left;        // x position of upper-left corner
		public int Top;         // y position of upper-left corner
		public int Right;       // x position of lower-right corner
		public int Bottom;      // y position of lower-right corner
	}
"@

# add new type with namespace
Add-Type -MemberDefinition $code -Name WinUtils -Namespace WindowsUtilities

# create rect object
$Rect = New-Object WindowsUtilities.WinUtils+RECT

# call GetWindowRect which returns the result inside the rect object
$null = [WindowsUtilities.WinUtils+Win32]::GetWindowRect(263640, [ref] $Rect)

# calculate width and height
$Width = $Rect.Right - $Rect.Left
$Height = $Rect.Bottom - $Rect.Top
Write-Host "$($Width) $($Height)"
