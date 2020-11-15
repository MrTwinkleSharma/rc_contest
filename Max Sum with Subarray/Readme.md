# Max Sum with Subarray
  David is a mathematics student he likes to create and solve problems, today he is solving a problem and the scenario is a array of length n [a1, a2 a3, ........an] is given to him, and he has to choose a non-empty subsequence of array of length less than or equal to n like the indices choosen wil be [1<= p1 < p2 < p3 .... k<=n]
let say he chooses the array p1, p2, p3, ....pk these all numbers are in sequence and selected from original array. Now according to question the sum of array is defined as p1 - p2 + p3 - p4 +..... + pk <br/> Now your Task is to maximize this sum according to question.
 
### Constraints

### Input Format 
```
First Line will Contains Number of t testcases 
Second Line Contains length of array n 
Third Line will contain space separated n numbers 
```

### Output Format 
```
Output the Maximum Sum which can be obtained from this array 
```

### Sample Input 1
2<br/>
4<br/>
1 2 3 4 <br/>
7<br/>
1 3 2 4 5 9 7<br/>
### Sample Output 1
4<br/>
10<br/>

Explanation:- <br/>
1.Try any combination of array manually but the sum of the array will be only maximized if [4] is choosen as subarray.<br/>
2. [3, 2, 9]  according to question the sum will be 3-2+9 = 10 which is only/one of the option to maximize the subarray.<br/>

### Sample Input 2


### Sample Output 2
