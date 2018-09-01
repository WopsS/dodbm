param (
    [string] $binDir
)

Get-ChildItem "$binDir/*-tests.exe" | ForEach-Object {
    Write-Host $_.BaseName
    Invoke-Expression $_.FullName

    if ($LastExitCode -ne 0)
    {
        exit $LastExitCode
    }
}