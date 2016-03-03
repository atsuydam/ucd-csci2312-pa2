<h1>PA2</h1>

Code has a memory fault that throws a sementation error when == is called in comparison operator. This operator functions fine in the point tests but causes a break when called in cluster testing. The first incidence of this occurs in the test_cluster_order. If commented out, the code will continue to compile and test okay though the test_cluster_addremove and test_cluster_contain functions before appearing again in the test_cluster_copying.

<h2>Point.cpp </h2>
This contains all the funcitons and definitions for the Point object. The point object holds a dynamic array of points of user defined dimensions in a euclidean space. Most tested functions return ok with exception of the ostream and istream operators. These compile but error in result.

<h2> Cluster.cpp </h2>
This contains all the functions and definitions for the cluster object. The cluster object uses linked list to access and set nodes of point objects. Sorting the list has been my bane and I was unable to complete this complete this function. The error has been tracked down to the insertion operator. 

<h3>Note </h3>
Yes, I'm aware I have a lot of work to do for P3. This was a lot of code to complete in a very busy three weeks. Code was just recently released in the corequisite class, Data structures, many of the errors here were problems I had with recent assignments in that class as well.  I believe with that and a tutor I will have this in full implementation soon.
