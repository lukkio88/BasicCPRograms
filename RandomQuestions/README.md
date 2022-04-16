# Random Questions

## Description
 Random generator of questions given a text file of questions
 
## How to clone
Just run
```
git clone https://github.com/lukkio88/BasicCPRograms.git
```
 
## How to build
 From the project folder run the following
 ```
 mkdir build && cd build && cmake .. && cmake --build . --config --Release
 ```
 
## How to run
 From where you built the project you can run for example
 ```
 ./random-questions ../questions.txt
 ```
 
## How to update or add new question file
To update a question file just add a new line at the end of the file and a new line.
To create a new question file just create a `.txt` whose content is similar to the example provided (i.e. one question per line and a new line at the end).