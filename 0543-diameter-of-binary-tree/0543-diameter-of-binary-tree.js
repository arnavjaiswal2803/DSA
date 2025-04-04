/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number}
 */
var diameterOfBinaryTree = function (root) {
    const maxDia = [-1];
    calculateDiameter(root, maxDia);
    return maxDia[0];
};

const calculateDiameter = (root, maxDia) => {
    if (root === null) return 0;

    const leftDia = calculateDiameter(root.left, maxDia);
    const rightDia = calculateDiameter(root.right, maxDia);

    maxDia[0] = Math.max(maxDia, leftDia, rightDia, leftDia + rightDia);

    return 1 + Math.max(leftDia, rightDia);
}