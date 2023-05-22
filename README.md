# IMDB-using-Linked-List
A C code that creates a IMDB-like application using linked list.

Most major websites collect feedback from their customers in order to improve the quality of
their services. The most common form of user feedback is ratings.
A rating consists mainly of three important pieces of information:
1. The user ID: this is the ID of the user who gave the rating.
2. The item ID: this is the ID of the item being rated. For example, the item can be a book, a
movie or a hotel.
3. The rating value: this is a numerical value that is usually an integer ranging from 1 to 5, where
1 is the lowest rating (user not satisfied) and 5 is the highest rating (user very satisfied).
Your goal in this project is to write a program that reads a list of ratings, stores them in memory
and answers a number of queries. Examples of queries are: What is the rating given by user i to
item j? What is the average rating of item j? What is (are) the highest rated item(s)?


Sample input and outputs:
INSERT 1 1 5
Customer rating (1, 1) is added successful
INSERT 1 2 1
Customer rating (1, 2) is added successful
INSERT 2 1 3.5
Customer rating (2, 1) is added successful
INSERT 2 2 5
Customer rating (2, 2) is added successful
RATING 2 1
Customer rating (2, 1) is: 3.5
RATING 2 3
Customer rating (2, 3) is: 0.0
INSERT 1 2 4
Customer rating (1, 2) is updated
AVERAGE 2
Average rating (2) is: 4.5
AVERAGE 3
Average rating (2) is: 0.0
