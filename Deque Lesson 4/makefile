###############################################################
# Program:
#     Assignment 04, DEQUE
#     Brother Kirby, CS235
# Author:
#     Mark Baldwin, Scott Tolman
# Summary:
#     This program will implement the deque data struture and 
#		use it to run the queue for lab assistance.
# Time:
#     Pair Programming:
#	  Mark: 5hrs
#	  Scott:
#
#		The most difficult part:
#			Mark: For me, the hardest part about this assignment
#			was laying out how to check for the empty deque. It 
#			did not occur to me til later in the week that I 
#			could use the .empty() method to do this and so I 
#			created dumby variables that I would set as needed
#			to keep track of this. Then it just came to me that 
#			.empty() was in my tool bag. Opps! Other than that 
#			things went well for me this week. 
#			
#			Scott:
###############################################################

##############################################################
# The main rule
##############################################################
a.out: deque.h assignment04.o nowServing.o
	g++ -o a.out assignment04.o nowServing.o
	tar -cf assignment04.tar *.h *.cpp makefile

##############################################################
# The individual components
#      assignment04.o : the driver program
#      nowServing.o   : the logic for the now serving program
##############################################################
assignment04.o: deque.h assignment04.cpp
	g++ -c assignment04.cpp

nowServing.o: nowServing.h nowServing.cpp deque.h
	g++ -c nowServing.cpp
