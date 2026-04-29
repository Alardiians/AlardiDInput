# AlardiDInput deployment script

$project64Dir = "C:\Users\Alardiians\Downloads\Project64-EM-1.0.3-PJ-3.0.1-win32\Project64-EM-1.0.3-PJ-3.0.1-win32"
$pluginDir = Join-Path $project64Dir "Plugin\Input"
$project64Cfg = Join-Path $project64Dir "Config\Project64.cfg"
$sourceDll = "C:\Users\Alardiians\Documents\WriteupsHTB\expressway.htb\pj64_dinput\PJ64_DInput\Debug\AlardiDInput.dll"
$targetDll = Join-Path $pluginDir "AlardiDInput.dll"
$oldTargetDll = Join-Path $pluginDir "PJ64_DInput.dll"
$oldIni = Join-Path $pluginDir "PJ64_DInput.ini"
$newIni = Join-Path $pluginDir "AlardiDInput.ini"

Write-Host "AlardiDInput Deployment" -ForegroundColor Green
Write-Host "=======================" -ForegroundColor Green

if (!(Test-Path $sourceDll)) {
    Write-Host "ERROR: Source DLL not found at $sourceDll" -ForegroundColor Red
    Write-Host "Make sure to build the project first!" -ForegroundColor Red
    exit 1
}

if (Test-Path $targetDll) {
    Write-Host "Removing existing DLL..." -ForegroundColor Yellow
    Remove-Item $targetDll -Force
}

if (Test-Path $oldTargetDll) {
    Write-Host "Removing old PJ64_DInput.dll..." -ForegroundColor Yellow
    Remove-Item $oldTargetDll -Force
}

if ((Test-Path $oldIni) -and !(Test-Path $newIni)) {
    Write-Host "Migrating existing config to AlardiDInput.ini..." -ForegroundColor Cyan
    Copy-Item $oldIni $newIni
}

if (Test-Path $project64Cfg) {
    $cfg = Get-Content $project64Cfg
    $cfg = $cfg -replace '^Controller Dll=.*$', 'Controller Dll=Input\AlardiDInput.dll'
    $cfg = $cfg -replace '^Controller Dll Ver=.*$', 'Controller Dll Ver=AlardiDInput'
    Set-Content $project64Cfg $cfg -Encoding ASCII
}

Write-Host "Copying new DLL..." -ForegroundColor Cyan
Copy-Item $sourceDll $targetDll

if (Test-Path $targetDll) {
    $sourceInfo = Get-Item $sourceDll
    $targetInfo = Get-Item $targetDll

    Write-Host "SUCCESS: DLL deployed successfully!" -ForegroundColor Green
    Write-Host "Source: $($sourceInfo.FullName)" -ForegroundColor Gray
    Write-Host "Target: $($targetInfo.FullName)" -ForegroundColor Gray
    Write-Host "Size: $($targetInfo.Length) bytes" -ForegroundColor Gray
    Write-Host "Modified: $($targetInfo.LastWriteTime)" -ForegroundColor Gray
    Write-Host ""
    Write-Host "Ready to test in Project64!" -ForegroundColor Green
} else {
    Write-Host "ERROR: Failed to copy DLL!" -ForegroundColor Red
    exit 1
}
