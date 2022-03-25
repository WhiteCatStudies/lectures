template <class T>
struct Node
{
    Node() = default;
    Node<T>* parent = nullptr;
    Node<T>* left = nullptr;
    Node<T>* right = nullptr;

    T key = T();

    bool operator bool() const
    {
        return (parent != nullptr) && (left != nullptr) && (right != nullptr);
    };
};


template <class T>
class BST
{
public:
    BST() = default;
    
    Node<T>* find(const T& key) const noexcept
    {
        const auto node = _find(_root, key);
        return node->key == key ? node : nullptr;
    };

    Node<T>* nextLargest(const Node<T>* node) const noexcept
    {
        if (node->right == nullptr)
        {
            return _rightAncestor(node);
        }

        return _leftDescendant(node->right);
    };

    void insert(const T& key) noexcept
    {
        if (empty())
        {
            _root = new Node<T>();
            _root->key = key;
            return;
        }
        
        auto node = _find(_root, key);
        if (node->key == key)
        {
            // no duplicates allowed
            return;
        }

        auto newNode = Node<T>();
        newNode->parent = node;

        if (key > node->key)
        {
            node->right = newNode;
        }
        else
        {
            node->reft = newNode;
        }
    };

    void remove(Node<T>* node)
    {
        if (node->right == nullptr)
        {
            if(node->parent == nullptr)
            {
                // the node is root
                _root->left = nullptr;
                delete _root;
                _root = node;
            }

            //if (node->parent->left->key == node->key)
            if(_isLeftChild(node))
            {
                //node is a left child
                node->parent->left = node->left;
            }
            // else if (node->parent->right->key == node->key)
            else if (_isRightChild(node))
            {
                node->parent->right = node->left;
            }
            else
            {
                //error
            }

            node->left = nullptr;
            delete node;
        }
        else
        {
            auto next = nextLargest(node);
            // case when node is the largest is processed above - 
            // the largest node has no right child

            node->key = next->key;

            if (_isRightChild(next))
            {
                //next is a leaf node
                next->parent->right == nullptr;
                delete next;
                return;
            }

            next->parent->left = next->right;
            next->right = nullptr;
            delete next;
        }
    }

    bool empty() const noexcept
    {
        return _root == nullptr;
    }

    ~BST()
    {
        if (_root->left != nullptr)
        {
            delete _root->left;
        }

        if (_root->right != nullptr)
        {
            delete _root->right;
        }
    };


private:
    Node<T>* _root = nullptr;

    Node<T>* _find(const Node<T>* node, const T& key) const noexcept
    {
        // returns either node with the given key or a node that could be its parent 
        if (node->key == key)
        {
            return node;
        }

        if(key < node->key)
        {
            if (node->left == nullptr)
            {
                return node;
            }

            return _find(node->left);
        }
        
        if (node->right == nullptr)
        {
            return node;
        }

        return _find(node->right);
    };

    Node<T>* _rightAncestor(const Node<T>* node) const noexcept
    {
        auto parent = node.parent;
        if (parent == nullptr)
        {
            return nullptr;
        }

        if(parent.key > node.key)
        {
            return parent;
        }

        return _rightAncestor(parent);
    };

    Node<T>* _leftDescendant(const Node<T>* node) const noexcept
    {
        if (node.left == nullptr)
        {
            return node;
        }

        return _leftDescendant(node->left);
    };

    static bool _isLeftChild(const Node<T>* node) noexcept
    {
        return node->parent->left->key == node->key;
    }

    static bool _isRightChild(const Node<T>* node) noexcept
    {
        return node->parent->right->key == node->key;
    }

};