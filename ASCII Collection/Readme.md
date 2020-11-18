# ASCII Collection
Robin is a Computer Science and Engineering Student, he has a subject Digital Logic and Circuit Design in his curriculam so recently he studied about character encoding for electronics communication and came to know about ASCII Code.
He is a Brilliant Student of his Batch, so he always remains curious to learn something new and creating innovative things so this time he created a simple game.
According to Game, Player will be given a array of characters (a-z and A-Z), and then Player will be asked to choose some or all characters from them and he will get score according to ascii value of that character.

But the RULES ARE:-
1. If you are choosing any character suppose 'b' then you can't choose again 'b' from that position and also you can't choose plus+1 and minus-1 character (i.e. 'a' or 'c') from whole array.
2. if you are choosing 'a' or 'z' then you will only can't choose 'b' in case of choosing 'a' and 'y' in case of 'z'. Because they both are extreme characters.
3. Same Rules are for UPPERCASE CHARACTER

### Constraints
### Input Format 
```
First Line will Contain number of test cases t
Second Line will Contain length of array n
On Third line n elements will contain a-z or A-Z

```

### Output Format 
```
Output the Maximum number Score Player(You) can earn by choosing the Characters wisely.
```

### Sample Input 1
1<br/>
8<br/>
a b c V s d e A<br/>

### Sample Output 1
563<br/>
-----------Explanation-----------<br/>
ASCII Code of these characters are as Following <br/>
a b c V s d e A<br/>
97 98 99 86 115 100 101 65<br/>
##### Choose Step By Step like:-
| Score | Array |  Removed (+ and -) | Added |
| ------ | ------ |  ----------  | ----------  |
| 0 | a b c V s d e A  |   None | A = 65|
| 65 | a b c V s d e |None | V = 86|
| 151 | a b c s d e |None | a = 97|
| 248 |  c s d e |b | c = 99|
| 347 |   s d e  |d | e = 101|
| 448 |   s |None| s = 115|
| 563 | Empty Now|None |NuLL|
<br/>
This answer is Maximum You can try your own manual try but you will unable to find more than this.

### Sample Input 2
2<br/>
6<br/>
e e f A j k <br/>
17<br/>
A B D e d E e e j k l s e S D E G<br/>

### Sample Output 2
374<br/>
1091<br/>
-----------Explanation-----------<br/>
ASCII Code of these characters are as Following<br/>
e e f A j k <br/>
101 101 102 65 106 107<br/>



ASCII Code of these characters are as Following <br/>
A B D e d E e e j k l s e S D E G<br/>
65 66 68 101 100 69 101 101 106 107 108 115 101 83 68 69 71<br/>
