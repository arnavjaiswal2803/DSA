/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func isBalanced(root *TreeNode) bool {
    return getHeight(root) != -1
}

func getHeight(root *TreeNode) int {
    if root == nil {
        return 0
    }

    leftHeight := getHeight(root.Left)
    if leftHeight == -1 {
        return -1
    }
    rightHeight := getHeight(root.Right) 
    if rightHeight == -1 {
        return -1
    }

    if math.Abs(float64(leftHeight) - float64(rightHeight)) > 1 {
        return -1
    }

    return 1 + max(leftHeight, rightHeight)
}