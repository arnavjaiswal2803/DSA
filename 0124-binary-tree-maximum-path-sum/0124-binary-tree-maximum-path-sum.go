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

    leftPathSum := calculateMaxPathSum(root.Left, maxxPathSum)
    rightPathSum := calculateMaxPathSum(root.Right, maxxPathSum)

    if leftPathSum > 0 && rightPathSum > 0 {
        *maxxPathSum = max(*maxxPathSum, root.Val + leftPathSum + rightPathSum)
    } else if leftPathSum > 0 {
        *maxxPathSum = max(*maxxPathSum, root.Val + leftPathSum)
    } else if rightPathSum > 0 {
        *maxxPathSum = max(*maxxPathSum, root.Val + rightPathSum)
    } else {
        *maxxPathSum = max(*maxxPathSum, root.Val)
    }

    return root.Val + max(0, leftPathSum, rightPathSum)
}