"use strict";
var node = /** @class */ (function () {
    function node(v) {
        this.val = v;
        this.left = null;
        this.right = null;
    }
    return node;
}());
;
function invertBinaryTree(root) {
    var ret = new /** @class */ (function () {
        function Node() {
        }
        return Node;
    }())(root.val);
    var invert = function (node, newNode) {
        if (node.left !== null) {
            newNode.right = new /** @class */ (function () {
                function Node() {
                }
                return Node;
            }())(node.left.val);
            invert(node.left, newNode.right);
        }
        if (node.right !== null) {
            newNode.left = new /** @class */ (function () {
                function Node() {
                }
                return Node;
            }())(node.right.val);
            invert(node.right, newNode.left);
        }
    };
    invert(root, ret);
    return ret;
}
