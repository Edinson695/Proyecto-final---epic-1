$ErrorActionPreference = "Stop"

$scriptDir = Split-Path -Parent $MyInvocation.MyCommand.Path
$repoRoot = Resolve-Path (Join-Path $scriptDir "..")
Set-Location $repoRoot

$projectName = "prog3_pf_epic1_feature1_v2026_01"
$outputZip = Join-Path $repoRoot "$projectName.zip"

$sourceCode = @(
    "include/utec/algebra/shape.h"
    "include/utec/algebra/tensor_backend.h"
)

$cppSources = @()
if (Test-Path "src") {
    $cppSources = Get-ChildItem -Path "src" -Filter "*.cpp" -File | ForEach-Object {
        Join-Path "src" $_.Name
    }
}

if ($cppSources.Count -gt 0) {
    $sourceCode += $cppSources
} elseif (Test-Path "src") {
    $sourceCode += "src"
}

$existingSources = $sourceCode | Where-Object { Test-Path $_ }
if ($existingSources.Count -eq 0) {
    throw "No se encontraron archivos para empaquetar."
}

if (Test-Path $outputZip) {
    Remove-Item $outputZip -Force
}

Add-Type -AssemblyName System.IO.Compression
Add-Type -AssemblyName System.IO.Compression.FileSystem
$zip = [System.IO.Compression.ZipFile]::Open($outputZip, [System.IO.Compression.ZipArchiveMode]::Create)
try {
    foreach ($entry in $existingSources) {
        $normalizedEntry = $entry -replace "\\", "/"
        if (Test-Path $entry -PathType Leaf) {
            $absolutePath = Join-Path $repoRoot $entry
            [System.IO.Compression.ZipFileExtensions]::CreateEntryFromFile(
                $zip,
                $absolutePath,
                $normalizedEntry,
                [System.IO.Compression.CompressionLevel]::Optimal
            ) | Out-Null
            continue
        }

        if (Test-Path $entry -PathType Container) {
            $directoryEntryName = $normalizedEntry.TrimEnd("/") + "/"
            $zip.CreateEntry($directoryEntryName) | Out-Null
        }
    }
}
finally {
    $zip.Dispose()
}

Write-Host "Archivo generado: $projectName.zip"
