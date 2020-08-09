
flag = -std=c++11

dssd: tree.h tree.cpp main.cpp LinkDict.cpp
		g++ $(shell root-config --libs --cflags) $(flag) $^ -o $@

LinkDict.cpp : tree.h Linkdef.h
	    #root 6
		#rootcling -f LinkDict.cpp -c $^
		# root 5
		rootcint -f LinkDict.cpp -c $^

clean:
	rm -rf dssd *Dict*
