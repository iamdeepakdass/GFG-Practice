<h2><a href="https://practice.geeksforgeeks.org/problems/minimum-deletitions1648/1?utm_source=geeksforgeeks&utm_medium=article_practice_tab&utm_campaign=article_practice_tab">Minimum Deletions</a></h2><h3>Difficulty Level : Easy</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size:18px">Given a string of S as input. Your task is to write a program to remove or delete the minimum number of characters from the string so that the resultant string is a palindrome.<br>
<strong>Note:</strong> The order of characters in the string should be maintained.</span></p>

<p><span style="font-size:18px"><strong>Example 1:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input: </strong>S<strong> </strong>=<strong> "</strong>aebcbda"
<strong>Output:</strong> 2
<strong>Explanation</strong>: Remove characters 'e' 
and 'd'.</span></pre>

<p><span style="font-size:18px"><strong>Example 2:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input</strong>: S = "geeksforgeeks"
<strong>Output:</strong> 8
<strong>Explanation</strong>: One of the possible result
string can be "eefee", so answer is 
13 - 5 = 8.
</span></pre>

<p><span style="font-size:18px"><strong>Your Task:&nbsp;&nbsp;</strong><br>
You don't need to read input or print anything. Your task is to complete the function&nbsp;<strong>minimumNumberOfDeletions()</strong>&nbsp;which takes the string <strong>S </strong>as inputs and returns the minimum number of deletions required to convert <strong>S</strong> into a pallindrome.<br>
<br>
<strong>Expected Time Complexity:</strong>&nbsp;O(|S|<sup>2</sup>)<br>
<strong>Expected Auxiliary Space:</strong>&nbsp;O(|S|<sup>2</sup>)<br>
<br>
<strong>Constraints:</strong><br>
1 ≤ |S| ≤ 10<sup>3</sup></span></p>
</div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>Amazon</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Strings</code>&nbsp;<code>Dynamic Programming</code>&nbsp;<code>Data Structures</code>&nbsp;<code>Algorithms</code>&nbsp;