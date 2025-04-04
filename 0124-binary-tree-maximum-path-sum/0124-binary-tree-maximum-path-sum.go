/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func maxPathSum(root *TreeNode) int {
    maxxPathSum := root.Val
    calculateMaxPathSum(root, &maxxPathSum)
    return maxxPathSum
}

func calculateMaxPathSum(root *TreeNode, maxxPathSum *int) int {
    if root == nil {
        return 0
    }

    leftPathSum := max(0, calculateMaxPathSum(root.Left, maxxPathSum))
    rightPathSum := max(0, calculateMaxPathSum(root.Right, maxxPathSum))

    *maxxPathSum = max(*maxxPathSum, root.Val + leftPathSum + rightPathSum)

    return root.Val + max(0, leftPathSum, rightPathSum)
}