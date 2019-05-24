echo A
ls
echo B;
mkdir temp
echo C
ls
echo D;
rm temp
echo E
ls -r
echo F;
ps
echo hello world
echo "hello world"
echo G
echo H && echo I
ps || echo J
echo K; ls
mkdir temp && rm -r temp
ls; echo L
echo "first" || echo "second" || echo "third"
echo M && echo N || echo O
cat file || echo file does not exist && echo P
ps; echo Q
ls -a || ls -r && echo R
echo S; echo T; echo U; echo V && echo W
exit

