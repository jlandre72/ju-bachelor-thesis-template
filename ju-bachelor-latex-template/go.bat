lualatex -shell-escape bachelor-report.tex
makeglossaries bachelor-report
biber bachelor-report
lualatex -shell-escape bachelor-report.tex


