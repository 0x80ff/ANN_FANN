Artificial Neural Network for Breast Cancer Detection
========

![alt tag](http://image.noelshack.com/fichiers/2014/21/1400608400-ann-picture.jpg)

The data used for training and testing the network comes from the [Center for Machine Learning and Intelligent Systems](http://archive.ics.uci.edu/ml/datasets/Breast+Cancer+Wisconsin+(Original))



![alt tag](http://image.noelshack.com/fichiers/2014/21/1400610486-schemareseaudeneurones.png)
Theoretical model: Network diagram
####Why ?

As part of my studies, I was able to perform a technology watch on a subject .
Always been interested in artificial intelligence and various controllers, I decided to make on the subject of artificial neural networks , their evolution and applications.

After seeing Brittany Wenger , 17, Wins Google Science Fair Grand Prize For Breast Cancer Diagnosis App, I decided to try to develop a basic application which replicates the behavior of detection of breast cancer using data from biopsies .

####How to use it?

First , compile the training program of the network, it will be fed with the data contained in the file dat.data previously formatted syntactically .
Then , compile the test program. But in the code, you must notify the test data . It is for this reason that I added a testingpool.data file containing data that the network has never seen .

In this way, the behavior of the network with unknown data can be observed .

####Conclusion

I did not observe any problems with the outcome of the network, except for a part of the input testing pool . I still concluded that the network is accurate enough with a small number of entries. A number of entries largest ensure greater reliability to the network and its application in the medical field then become possible. Thus confirming the work performed by Brittany Wenger, in its data collection to improve its network in order to have a margin of error tends to zero .

##Requirements

GNU GCC Compiler

##Contributing

All contributions are welcome to improve the user experience.
