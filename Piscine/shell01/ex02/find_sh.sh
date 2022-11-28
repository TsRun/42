find . -type f -regex ".*\.sh$" | sed "s/.*\///g; s/...$//g"
