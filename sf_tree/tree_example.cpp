#include <memory>
#include <map>
using namespace std;


class TreeNode: public enable_shared_from_this<TreeNode> {
    typedef map<char, shared_ptr<TreeNode>> TChildren;
    TChildren Children;
    weak_ptr<TreeNode> Parent;
    weak_ptr<TreeNode> PrefixLink;

    TreeNode(shared_ptr<TreeNode> parent, char c)
        : Parent(parent)
        , PrefixLink(parent ? FindPrefixLink(parent->GetPrefixLink(), c) : weak_ptr<TreeNode>())
    {}

    shared_ptr<TreeNode> FindPrefixLink(shared_ptr<TreeNode>, char);
public:
    ~TreeNode() {}
    shared_ptr<TreeNode> GetParent() const { return Parent.lock(); }
    shared_ptr<TreeNode> GetChild(char c) const {
        TChildren::const_iterator it = Children.find(c);
        if (it == Children.end())
            return shared_ptr<TreeNode>();
        return it->second;
    }

    shared_ptr<TreeNode> GetPrefixLink() {
        shared_ptr<TreeNode> resLink = PrefixLink.lock();
        if (!resLink)
            resLink = shared_from_this();
        return resLink;
    }

    static shared_ptr<TreeNode> CreateNode(shared_ptr<TreeNode> parent, char c=0) {
        TreeNode* node = new TreeNode(parent, c);
        return node->shared_from_this();
    }
};
