#quick little shell script to recompile library,
#recompile an executable and run it.
make fclean && make && clear
gcc main.c libftprintf.a
echo "


"
./a.out | cat -e
#sh clean.sh

echo "



"
