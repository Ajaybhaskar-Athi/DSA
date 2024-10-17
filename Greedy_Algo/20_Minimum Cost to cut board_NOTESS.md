
The problem involves minimizing the cost of breaking a board of dimensions m by 𝑛 into smaller squares using given costs for horizontal and vertical cuts

# Input Explanation:

Dimensions: The board has a length of m and a width of 𝑛
Cutting Costs:
The array x[] contains the costs for making horizontal cuts (lengthwise).
The array y[] contains the costs for making vertical cuts (width wise).


Cutting edges with the **maximum cost** first is essential in minimizing the total cutting cost in the board cutting problem. Here's why:

### 1. **Cost Contribution**
   - When you make a cut, the cost is multiplied by the number of pieces you have at that moment. Therefore, if you make a cut that has a higher cost while you have fewer pieces, it will contribute less to the total cost compared to making that cut later when the number of pieces has increased.
   - **Formula**: 
     Total Cost+= cost of cut * number of pieces before cut
    

### 2. **Greedy Strategy**
   - This approach is based on a greedy algorithm strategy, where you make the locally optimal choice (in this case, the maximum cost cut) with the hope of finding a global optimum (minimized total cost).
   - By cutting the most expensive edges first, you are ensuring that those costs affect the total less when there are fewer pieces, hence reducing their overall impact on the total cost.

### 3. **Example for Clarification**
Let’s illustrate this with an example.

#### Example:
- Suppose you have a board that requires the following cuts:
  - Horizontal cuts costs: [5, 1, 2] (sorted: [5, 2, 1])
  - Vertical cuts costs: [3, 4] (sorted:[4, 3])

**Order of Cuts**:
1. **First**, make the horizontal cut of cost 5:
   - Total Pieces before cut: **1**
   - Cost Contribution: (5 X 1 = 5)
   - Total Pieces after cut: **2**
   
2. **Next**, make the vertical cut of cost 4:
   - Total Pieces before cut: **2**
   - Cost Contribution: (4 x2=8)
   - Total Pieces after cut: **4**
   
3. **Next**, make the horizontal cut of cost 2:
   - Total Pieces before cut: **4**
   - Cost Contribution: (2 x 4=8)
   - Total Pieces after cut: **8**

4. **Finally**, make the vertical cut of cost 3:
   - Total Pieces before cut: **8**
   - Cost Contribution: \(3 X 8 = 24\)
   - Total Pieces after cut: **16**

**Total Cost**: 
- The total cost accumulated is:   5 + 8 + 8 + 24 = 45


### Conclusion
If you had made the cuts in a different order, such as starting with the smaller cuts first, the cost associated with the higher cuts would have multiplied by a greater number of pieces, leading to a higher total cost overall.

### Summary
By cutting the edges with the maximum cost first, you effectively minimize the cost contribution of those cuts by reducing the number of pieces they influence, thus leading to a minimized total cost for breaking the board into squares.
