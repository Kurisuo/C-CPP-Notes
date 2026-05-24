



bool accept(){ 
    cout << "Do you wish to proceed? Y/N \n";
    char answer = 0;
    cin >> answer;
    if (answer == 'y') return true;
    return false;
}

switch(answer){ 
    case 'y':
        return true;
    case 'n':
    return false;

    default:
        cout << "...\n";
        return false;
}


void action(){ 


    while(true){ 

        cout << "enter action:\n"
        string act;
        cin >> act;
        Point delta{0, 0};
        for (char ch : act){ 
            switch(ch){
                case 'u':
                case 'n':
                    ++delta.y;
                    break;
                case 'r':
                case 'e':
                    ++delta.x;
                    break;
                default:
                    cout << "...\n";

            } 
            move(current + delta * scale);
            update_display();
        }

    }

}