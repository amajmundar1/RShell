echo A && echo B || ps || echo C
(echo A && echo B) || (ps || echo C)
echo D; ls && mkdir temp && rm -r temp
(echo D; ls) && (mkdir temp && rm -r temp)
echo "first" || echo "second" || echo "third" || echo "fourth"
(echo "first" || echo "second") || (echo "third" || echo "fourth")
cat file || echo file does not exist && echo E; ps
(cat file || echo file does not exist) && (echo E; ps)
ls -a || ls -r && echo F && exit
(ls -a || ls -r) && (echo F && exit)
