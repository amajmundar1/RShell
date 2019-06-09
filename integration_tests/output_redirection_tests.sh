ls > newFile.h 
echo test > newFile.h && cat newFile.h
ps > newFile.h || echo A
ls | wc >> newFile.h; cat newFile.h
cat newFile.h | tr a-z c-za-b > newFile.h && umask || echo B
rm newFile.h
exit

