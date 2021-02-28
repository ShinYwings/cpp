class quadNode {
    private:
            int data;
            quadNode* topLeft;
            quadNode* topRight;
            quadNode* bottomLeft;
            quadNode* bottomRight;
    
    public:
            quadNode(int val = 0, quadNode* tl = NULL, quadNode* tr  = NULL, quadNode* bl  = NULL, quadNode* br  = NULL) :
                data(val), topLeft(tl), topRight(tr), bottomLeft(bl), bottomRight(br) {} 
            void setData(int val) { data = val; }
            void setTopLeft(quadNode* tl) { topLeft = tl; }
            void setTopRight(quadNode* tr) { topRight = tr; }
            void setBottomLeft(quadNode* bl) { bottomLeft = bl; }
            void setBottomRight(quadNode* br) { bottomRight = br; }
            int getData() { return data; }
            quadNode* getTopLeft() { return topLeft; }
            quadNode* getTopRight() { return topRight; }
            quadNode* getBottomLeft() { return bottomLeft; }
            quadNode* getBottomRight() { return bottomRight; }
};

class quadTree {

    private:
            quadNode* root;

    public:
            quadTree() : root(NULL) {}
            void setRoot(quadNode* node) { root = node; }
            quadNode* getRoot() { return root; }
            bool isEmpty() { return root = NULL; }

            void preOrder()
            {
                printf("\n");
                preOrder(root);
            }
            void preOrder(quadNode* node)
            {
                if ( node != NULL ){
                    printf("(");
                    printf("%d", node->getData());
                    preOrder(node->getTopLeft());
                    preOrder(node->getTopRight());
                    preOrder(node->getBottomLeft());
                    preOrder(node->getBottomRight());
                    printf(")");
                }   
            }
            
            // int getCount()
            // {
            //     return isEmpty() ? 0 : getCount(root);
            // }
            // int getCount(quadNode* node)
            // {
            //     if ( node == NULL ) return 0;
            //     return 1 + getCount(node->getTopLeft()) + getCount(node->getTopRight()) + getCount(node->getBottomLeft()) + getCount(node->getBottomRight());
            // }
};