interface TreeNode {
  left: TreeNode | null;
  right: TreeNode | null;
  val: string;
}
class node implements TreeNode {
  left: TreeNode | null;
  right: TreeNode | null;
  val: string;
  constructor(v: string) {
    this.val = v;
    this.left = null;
    this.right = null;
  }
}

function invertBinaryTree(root: TreeNode): TreeNode {
  var ret = new node(root.val);
  const invert = (nd: TreeNode, newNode: TreeNode) => {
    if (nd.left !== null) {
      newNode.right = new node(nd.left.val);
      invert(nd.left, newNode.right);
    }
    if (nd.right !== null) {
      newNode.left = new node(nd.right.val);
      invert(nd.right, newNode.left);
    }
  };
  invert(root, ret);
  return ret;
}
