
class KeyboardEvents {
    public:
        void handlePlayerInput(int key, bool isPressed);
        bool mIsMovingUp = false;
        bool mIsMovingDown = false;
        bool mIsMovingLeft = false;
        bool mIsMovingRight = false;
};

void KeyboardEvents::handlePlayerInput(int key, bool isPressed) {

    // W => 22, A => 0, S => 18, D => 3 
    if(key == 22) 
        mIsMovingUp = isPressed;
    else if (key == 18)
        mIsMovingDown = isPressed;
    else if (key == 0)
        mIsMovingLeft = isPressed;
    else if (key == 3)
        mIsMovingRight = isPressed;
}