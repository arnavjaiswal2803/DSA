/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func isBalanced(root *TreeNode) bool {
    isHeightBalanced := true;
    getHeight(root, &isHeightBalanced)
    return isHeightBalanced
}

func getHeight(root *TreeNode, isHeightBalanced *bool) int {
    if root == nil {
        return 0
    }

    left := getHeight(root.Left, isHeightBalanced)
    right := getHeight(root.Right, isHeightBalanced)

    if math.Abs(float64(left) - float64(right)) > 1 {
        *isHeightBalanced = false
    }

    return 1 + max(left, right)
}