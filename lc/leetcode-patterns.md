# LeetCode Patterns — Core Concepts to Memorize

Distilled from the transcript. Goal: get these so engraved that writing them feels as natural as a `for` loop. The advice across all three talks converges on the same list — master these before touching exotic stuff.

**Priority order (most common → less common):**
1. Hashmaps
2. Recursion (+ decision trees)
3. DFS / BFS
4. Binary Search
5. Sliding Window / Two Pointers
6. Heaps
7. Arrays fundamentals (prefix sums, sorting)
8. Union Find
9. Topological Sort
10. Dijkstra
11. Dynamic Programming (learn *after* the above)

---

## 1. Hashmaps — "The Forbidden Jutsu"

**Why it matters:** Most common pattern. O(1) average insert/lookup/delete. If you're stuck optimizing, the first question is *"would a hashmap help?"*

**Use cases:**
- Count occurrences (chars in a string, frequencies)
- Build adjacency list for graphs
- Replace O(n) inner-loop search with O(1) lookup (e.g. Two Sum)
- Memoization for DP / recursion
- Visited-set for DFS/BFS (as a hash *set*)

```python
# Two Sum — canonical hashmap use
def two_sum(nums, target):
    seen = {}  # value -> index
    for i, x in enumerate(nums):
        if target - x in seen:
            return [seen[target - x], i]
        seen[x] = i

# Frequency counter
from collections import Counter
freq = Counter("aabbc")  # {'a':2, 'b':2, 'c':1}
```

---

## 2. Recursion + Decision Trees

**Why it matters:** Foundation for trees, backtracking, DP (memoization), graphs. If recursion feels shaky, those topics all feel impossible.

**Must understand:**
- **Base case** — when to stop
- **Recursive step** — how the problem shrinks
- **Call stack cost** — recursion isn't free; stack depth = extra memory
- **Decision tree** — at each node, what choices exist?

```python
# Template: decision tree / backtracking
def backtrack(path, choices):
    if is_goal(path):
        result.append(path[:])
        return
    for choice in choices:
        path.append(choice)
        backtrack(path, next_choices(choice))
        path.pop()  # undo

# Subsets — classic decision tree (include / exclude)
def subsets(nums):
    res = []
    def dfs(i, cur):
        if i == len(nums):
            res.append(cur[:])
            return
        cur.append(nums[i])  # include
        dfs(i + 1, cur)
        cur.pop()            # exclude
        dfs(i + 1, cur)
    dfs(0, [])
    return res
```

---

## 3. DFS & BFS

**Why it matters:** Building blocks for nearly every graph algorithm (Dijkstra, Kruskal, Prim, topo sort). Show up on trees, matrices, and adjacency lists. Same algorithm, different code shape depending on graph type.

**Complexity:** O(V + E) — visit each node/edge at most once.

### DFS (recursive)
```python
def dfs(node, visited, graph):
    if node in visited:
        return
    visited.add(node)
    # process(node)
    for nei in graph[node]:
        dfs(nei, visited, graph)
```

### DFS (iterative, with stack)
```python
def dfs_iter(start, graph):
    visited, stack = set(), [start]
    while stack:
        node = stack.pop()
        if node in visited:
            continue
        visited.add(node)
        for nei in graph[node]:
            if nei not in visited:
                stack.append(nei)
```

### BFS (queue — shortest path in unweighted graphs)
```python
from collections import deque

def bfs(start, graph):
    visited = {start}
    q = deque([start])
    while q:
        node = q.popleft()
        # process(node)
        for nei in graph[node]:
            if nei not in visited:
                visited.add(nei)
                q.append(nei)
```

### Matrix DFS/BFS
```python
ROWS, COLS = len(grid), len(grid[0])
DIRS = [(1,0), (-1,0), (0,1), (0,-1)]

def in_bounds(r, c):
    return 0 <= r < ROWS and 0 <= c < COLS

def dfs(r, c, visited):
    if not in_bounds(r, c) or (r, c) in visited or grid[r][c] == 0:
        return
    visited.add((r, c))
    for dr, dc in DIRS:
        dfs(r + dr, c + dc, visited)
```

**Interview gotcha (from transcript):** be able to explain what goes wrong if you remove each line.
- No `visited` check → infinite loop on cycles
- No bounds check → index out of bounds
- No early return on invalid cell → overcount / wrong answer

---

## 4. Binary Search

**Why it matters:** O(log n) vs O(n). Easy when the problem screams "search a sorted array." Hard when the binary search is hidden inside another problem.

**When to suspect binary search:**
- Sorted input
- "Find minimum X such that ..." / "find maximum X such that ..."
- Answer lies in a numeric range and you can check a candidate in O(n)

```python
# Classic: find target in sorted array
def binary_search(nums, target):
    l, r = 0, len(nums) - 1
    while l <= r:
        mid = (l + r) // 2
        if nums[mid] == target:
            return mid
        elif nums[mid] < target:
            l = mid + 1
        else:
            r = mid - 1
    return -1

# Lower bound — leftmost index where nums[i] >= target
def lower_bound(nums, target):
    l, r = 0, len(nums)
    while l < r:
        mid = (l + r) // 2
        if nums[mid] < target:
            l = mid + 1
        else:
            r = mid
    return l

# Binary search on answer — "can we do it with capacity k?"
def min_capacity(weights, days):
    def can_ship(cap):
        d, cur = 1, 0
        for w in weights:
            if cur + w > cap:
                d += 1
                cur = 0
            cur += w
        return d <= days
    l, r = max(weights), sum(weights)
    while l < r:
        mid = (l + r) // 2
        if can_ship(mid):
            r = mid
        else:
            l = mid + 1
    return l
```

---

## 5. Sliding Window / Two Pointers

**Why it matters:** Turns O(n²) nested loops into O(n). The "aha" is that the two pointers only ever move forward.

**Signals:**
- Contiguous subarray / substring
- "Longest / shortest / max / min window with property X"
- Sorted array + pair-sum style questions

```python
# Variable-size window — longest substring without repeats
def longest_unique(s):
    seen = {}
    l = res = 0
    for r, ch in enumerate(s):
        if ch in seen and seen[ch] >= l:
            l = seen[ch] + 1
        seen[ch] = r
        res = max(res, r - l + 1)
    return res

# Fixed-size window — max sum of k consecutive
def max_k_sum(nums, k):
    cur = sum(nums[:k])
    res = cur
    for i in range(k, len(nums)):
        cur += nums[i] - nums[i - k]
        res = max(res, cur)
    return res

# Two pointers — sorted array, two-sum
def two_sum_sorted(nums, target):
    l, r = 0, len(nums) - 1
    while l < r:
        s = nums[l] + nums[r]
        if s == target: return [l, r]
        if s < target: l += 1
        else: r -= 1
```

---

## 6. Heaps (Priority Queues)

**Why it matters:** O(log n) insert/pop-min. O(1) peek. **O(n) heapify** when you have all values up front (common interview mistake: people say n log n).

**Use cases:**
- "Top K" problems
- Streaming min/max
- Dijkstra, merge k sorted lists
- Anywhere you repeatedly need the smallest/largest

```python
import heapq

# Min-heap (default in Python)
h = []
heapq.heappush(h, 3)
heapq.heappush(h, 1)
heapq.heappop(h)  # 1

# Heapify — O(n)
nums = [5, 3, 8, 1]
heapq.heapify(nums)

# Max-heap — negate values
max_h = []
heapq.heappush(max_h, -5)
-heapq.heappop(max_h)  # 5

# Top K largest — O(n log k)
def top_k(nums, k):
    h = []
    for x in nums:
        heapq.heappush(h, x)
        if len(h) > k:
            heapq.heappop(h)
    return h  # k largest
```

---

## 7. Arrays — Prefix Sums & Fundamentals

**Why it matters:** Arrays are everywhere. Prefix sums unlock O(1) range-sum queries after O(n) preprocessing.

```python
# Prefix sum — range sum in O(1)
def build_prefix(nums):
    prefix = [0]
    for x in nums:
        prefix.append(prefix[-1] + x)
    return prefix

def range_sum(prefix, i, j):  # inclusive i..j
    return prefix[j + 1] - prefix[i]

# 2D prefix sum
def build_2d(mat):
    R, C = len(mat), len(mat[0])
    ps = [[0] * (C + 1) for _ in range(R + 1)]
    for r in range(R):
        for c in range(C):
            ps[r+1][c+1] = mat[r][c] + ps[r][c+1] + ps[r+1][c] - ps[r][c]
    return ps
```

---

## 8. Union Find (Disjoint Set Union)

**Why it matters:** Efficient connected-components, cycle detection in undirected graphs, Kruskal's MST.

**Complexity:** ~O(α(n)) per op with path compression + union by rank — effectively O(1).

```python
class UnionFind:
    def __init__(self, n):
        self.parent = list(range(n))
        self.rank = [1] * n
        self.components = n

    def find(self, x):
        while self.parent[x] != x:
            self.parent[x] = self.parent[self.parent[x]]  # path compression
            x = self.parent[x]
        return x

    def union(self, a, b):
        ra, rb = self.find(a), self.find(b)
        if ra == rb:
            return False
        if self.rank[ra] < self.rank[rb]:
            ra, rb = rb, ra
        self.parent[rb] = ra
        if self.rank[ra] == self.rank[rb]:
            self.rank[ra] += 1
        self.components -= 1
        return True
```

---

## 9. Topological Sort

**Why it matters:** Ordering tasks with dependencies. Only works on **DAGs** (directed, acyclic). Detects cycles as a bonus.

### DFS-based
```python
def topo_sort_dfs(graph):  # graph: adjacency list
    visited, stack = set(), []
    def dfs(node):
        if node in visited: return
        visited.add(node)
        for nei in graph[node]:
            dfs(nei)
        stack.append(node)
    for node in graph:
        dfs(node)
    return stack[::-1]
```

### Kahn's Algorithm (BFS-based)
```python
from collections import deque, defaultdict

def topo_sort_kahn(n, edges):
    graph = defaultdict(list)
    indeg = [0] * n
    for u, v in edges:
        graph[u].append(v)
        indeg[v] += 1
    q = deque(i for i in range(n) if indeg[i] == 0)
    order = []
    while q:
        u = q.popleft()
        order.append(u)
        for v in graph[u]:
            indeg[v] -= 1
            if indeg[v] == 0:
                q.append(v)
    return order if len(order) == n else []  # [] = cycle detected
```

---

## 10. Dijkstra's Shortest Path

**Why it matters:** Shortest path in a weighted graph with **non-negative** edges. Built on BFS + heap.

**Complexity:** O(E log V)

```python
import heapq

def dijkstra(graph, start):  # graph[u] = [(v, weight), ...]
    dist = {start: 0}
    pq = [(0, start)]
    while pq:
        d, u = heapq.heappop(pq)
        if d > dist.get(u, float('inf')):
            continue
        for v, w in graph[u]:
            nd = d + w
            if nd < dist.get(v, float('inf')):
                dist[v] = nd
                heapq.heappush(pq, (nd, v))
    return dist
```

---

## 11. Dynamic Programming (Study Last)

**Why it matters last:** Heavily hyped, less common than people think. Many companies ban DP questions. Learn the *famous* ones — don't grind 200 DP problems.

**Must-know DP problems (per transcript):**
- Longest Common Subsequence
- Coin Change
- House Robber
- Longest Increasing Subsequence
- 0/1 Knapsack
- Edit Distance

**Two flavors:**
1. **Top-down (memoization):** recursion + cache
2. **Bottom-up (tabulation):** iterative, build table

```python
# Coin Change — bottom up
def coin_change(coins, amount):
    dp = [float('inf')] * (amount + 1)
    dp[0] = 0
    for a in range(1, amount + 1):
        for c in coins:
            if a - c >= 0:
                dp[a] = min(dp[a], dp[a - c] + 1)
    return dp[amount] if dp[amount] != float('inf') else -1

# Top-down template
from functools import lru_cache

def solve(inputs):
    @lru_cache(maxsize=None)
    def dp(state):
        if base_case(state):
            return base_value
        return combine(dp(next_state) for next_state in transitions(state))
    return dp(initial_state)
```

---

## Meta-advice from the transcript

1. **Depth > breadth.** Re-solve easy problems until they're automatic. A rock-solid DFS beats a sloppy segment tree.
2. **For each core algorithm, know what every line does.** Remove a line → what breaks? (infinite loop, OOB, overcounting?)
3. **Skip the obscure.** KMP, Floyd-Warshall, Cherry Pickup II — rarely show up. Skip until the common stuff is locked in.
4. **Learn DP *after* the other 10.** Prioritize ROI.
5. **Hashmaps everywhere.** If stuck optimizing, ask "hashmap?" first.

## Minimum-spanning-tree (briefly)

Rare but worth knowing *one* of:
- **Kruskal's** — sort edges, union-find to add cheapest non-cycle edge
- **Prim's** — like Dijkstra, grow tree from a node using a heap

Pick one, skip the other.
