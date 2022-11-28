cat /etc/passwd | sed '1~2d' | cut -f1 -d":" | rev | sort -r | sed -n "${FT_LINE1},${FT_LINE2}p" | sed -z "s/\n/, /g; s/, $/./g"
