	if (n <= 2)
		return 0;
	std::vector<bool> flags(n, true);
	std::vector<int> primes;
	for (int i = 2; i < n; i++) {
		if (flags[i]) {
			primes.push_back(i);
		}
	}
	for (int i = 0; i < primes.size(); i++) {
		int p = primes[i];
		if (p * p >= n)
			break;
		for (int j = 0; j < primes.size(); j++) {
			if (p * primes[j] >= n)
				break;
			flags[p * primes[j]] = false;
		}
	}
	int count = 0;
	for (int i = 2; i < n; i++) {
		if (flags[i]) {
			count++;
		}
	}
	return count;
}
"""
"""
You are given the root of a binary tree and an integer targetSum.
Return true if the tree has a root-to-leaf path such that adding up all the values along the path equals targetSum.
A leaf is a node with no children.
Example 1:
Input: root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22
Output: true
"""
from collections import deque
from tree import *
def hasPathSum(root, targetSum):
    """
    :type root: TreeNode
    :type targetSum: int
    :rtype: bool
    """
    if not root:
        return False
    que = deque()
    que.append(root)
    targetSum -= root.val
    while que:
        cur = que.popleft()
        if not cur.left and not cur.right and targetSum == 0:
            return True
        if cur.left:
            que.append(cur.left)
            cur.left.val += cur.val
            targetSum -= cur.left.val
        if cur.right:
            que.append(cur.right)
            cur.right.val += cur.val
            targetSum -= cur.right.val
    return False
"""
You are given the root of a binary tree and an integer targetSum.
Return all root-to-leaf paths where each path's sum equals targetSum.
A leaf is a node with no children.
Example 1:
Input: root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22
Output: [[5,4,11,2],[5,8,4,5]]
"""
def pathSum(root, targetSum):
    res = []
    def findPath(root, targetSum, temp, res):
        if not root:
            return
        if not root.left and not root.right and root.val == targetSum:
            res.append(temp + [root.val])
            return
        findPath(root.left, targetSum - root.val, temp + [root.val], res)
        findPath(root.right, targetSum - root.val, temp + [root.val], res)
    findPath(root, targetSum, [], res)
    return res
"""
You are given the root of a binary tree and an integer targetSum.
Return all root-to-leaf paths where each path's sum equals targetSum.
A leaf is a node with no children.
Example 1:
Input: root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22
Output: [[5,4,11,2],[5,8,4,5]]
"""
def pathSum2(root, targetSum):
    res = []
    def findPath(root, targetSum, temp, res):
        if not root:
            return
        if not root.left and not root.right and root.val == targetSum:
            res.append(temp + [root.val])
            return
        findPath(root.left, targetSum - root.val, temp + [root.val], res)
        findPath(root.right, targetSum - root.val, temp + [root.val], res)
    findPath(root, targetSum, [], res)
    return res
"""
You are given the root of a binary tree and an integer targetSum.
Return all root-to-leaf paths where each path's sum equals targetSum.
A leaf is a node with no children.
Example 1:
Input: root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22
Output: [[5,4,11,2],[5,8,4,5]]
"""
def pathSum3(root, targetSum):
    res = []
    def findPath(root, targetSum, temp, res):
        if not root:
            return
        if not root.left and not root.right and root.val == targetSum:
            res.append(temp + [root.val])
            return
        findPath(root.left, targetSum - root.val, temp + [root.val], res)
        findPath(root.right, targetSum - root.val, temp + [root.val], res)
    findPath(root, targetSum, [], res)
    return res
"""
You are given the root of a binary tree and an integer targetSum.
Return all root-to-leaf paths where each path's sum equals targetSum.
A leaf is a node with no children.
Example 1:
Input: root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22
Output: [[5,4,11,2],[5,8,4,5]]
"""
def pathSum4(root, targetSum):
    res = []
    def findPath(root, targetSum, temp, res):
        if not root:
            return
        if not root.left and not root.right and root.val == targetSum:
            res.append(temp + [root.val])
            return
        findPath(root.left, targetSum - root.val, temp + [root.val], res)
        findPath(root.right, targetSum - root.val, temp + [root.val], res)
    findPath(root, targetSum, [], res)
    return res
"""
You are given the root of a binary tree and an integer targetSum.
Return all root-to-leaf paths where each path's sum equals targetSum.
A leaf is a node with no children.
Example 1:
Input: root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22
Output: [[5,4,11,2],[5,8,4,5]]
"""
def pathSum5(root, targetSum):
    res = []
    def findPath(root, targetSum, temp, res):
        if not root:
            return
        if not root.left and not root.right and root.val == targetSum:
            res.append(temp + [root.val])
            return
        findPath(root.left, targetSum - root.val, temp + [root.val], res)
        findPath(root.right, targetSum - root.val, temp + [root.val], res)
    findPath(root, targetSum, [], res)
    return res
"""
You are given the root of a binary tree and an integer targetSum.
Return all root-to-leaf paths where each path's sum equals targetSum.
A leaf is a node with no children.
Example 1:
Input: root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22
Output: [[5,4,11,2],[5,8,4,5]]
"""
def pathSum6(root, targetSum):
    res = []
    def findPath(root, targetSum, temp, res):
        if not root:
            return
        if not root