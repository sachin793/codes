void printSibling(Node* node)
{
    printf("hello\n");
    if(node==NULL)
    {
        return ;
    }
    else
        if(node->left!=NULL && node->right!=NULL)
        {
            printSibling(node->left);
            printSibling(node->right);
        }
        else
        {
            cout<<node->left->data<<" ";
            printSibling(node->left);
        }
        else
        {
            cout<<node->right->data<<" ";
            printSibling(node->right);
        }
}