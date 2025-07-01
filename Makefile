compiler = g++
files = Main.cpp User.cpp Helper.cpp Post.cpp Pages.cpp Activity.cpp Date.cpp Comment.cpp C_Array.cpp Memory.cpp App.cpp
flags = -o
exe = main


build:
	$(compiler) $(files) $(flags) $(exe)

run:
	./$(exe)