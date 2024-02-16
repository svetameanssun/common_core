#VARIABLES
files := file1.c file2.c
some_file: $(files)
	echo "Look at this variable: " $(files)
	touch some_file

file1.c:
	echo "int main() { return 0; }" > file1.c
	
file2.c:
	echo "int main() { return 0; }" > file2.c

clean:
	rm -f file1 file2 some_file ex.c example example_prog example.o

#SINGLE OR DOUBLE QUOTES

#a := one two
#b := 'one two' #not recommended
#all:
#	printf '$a '
#	printf $b

x := 'dude'
y := sis
z := "goddess"

all:
	echo $(y)
	echo ${z}
#bad parctice↓
	echo $x
#-------------------------------------------------------------------
#some_file: 
#	touch some_file
#clean:
#	rm -f some_file
#-------------------------------------------------------------------

#example_prog: example.o
#	cc example.o -o example_prog
#	echo "third"

#example.o: ex.c
#	cc -c example.c -o example.o
#	echo "second"
#ex.c:
#	echo "int main() { return 0; }" > ex.c
#	echo "first"






