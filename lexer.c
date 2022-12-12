#include<stdio.h>


int i = 0;
    char buffer[1000];
    int pos;
    char ch;
    FILE *code;
    char line[100];
    char temp[20];
int flag = 0;

void operators(){

     //arithmetic operator
        if(ch == '+'){
            printf("\n%c addition", ch);
        }
        else if(ch == '-'){
            printf("\n%c subtraction", ch);
        }
        else if(ch == '*'){
            printf("\n%c multiplication", ch);
        }
        else if(ch == '/'){
            printf("\n%c division", ch);
        }
        else if(ch == '^'){
            printf("\n%c exponent", ch);
        }
        else if(ch == '%'){
            printf("\n%c modulo", ch);
        }
        else if(ch == '@'){
            printf("\n%c int division", ch);
        }
        else if(ch == '='){
           pos = ftell(code);
           temp[0] = fgetc(code);
           if(temp[0] == '='){
            printf("\n%c%c ==", ch, temp[0]);
           }
           else{
            printf("\n%c equal", ch);
            fseek(code,pos,SEEK_SET);
           }
        }
        else if(ch == '>'){
           pos = ftell(code);
           temp[0] = fgetc(code);
           if(temp[0] == '='){
            printf("\n%c%c >=", ch, temp[0]);
           }
           else{
            printf("\n%c >", ch);
            fseek(code,pos,SEEK_SET);
           }
        }
        else if(ch == '<'){
           pos = ftell(code);
           temp[0] = fgetc(code);
           if(temp[0] == '='){
            printf("\n%c%c <=", ch, temp[0]);
           }
           else{
            printf("\n%c <", ch);
            fseek(code,pos,SEEK_SET);
           }
        }
        else if(ch == '!'){
           pos = ftell(code);
           temp[0] = fgetc(code);
           if(temp[0] == '='){
            printf("\n%c%c !=", ch, temp[0]);
           }
           else{
            fseek(code,pos,SEEK_SET);
           }
        }
        else{
            flag++;
        }

}

void deli_bracks(){

    if(ch == ','){
        printf("\n%c separator", ch);
    }
    else if(ch == '('){
        printf("\n%c openParenthesis", ch);
    }
    else if(ch == ')'){
        printf("\n%c closedParenthesis", ch);
    }
    else if(ch == '['){
        printf("\n%c openBracket", ch);
    }
    else if(ch == ']'){
        printf("\n%c closedBracket", ch);
    }
    else if(ch == '{'){
        printf("\n%c openCurly", ch);
    }
    else if(ch == '}'){
        printf("\n%c closedCurly", ch);
    }
    else if(ch == '\''){
        printf("\n%c singleQuote", ch);
    }
    else if(ch == '\"'){
        printf("\n%c doubleQuote", ch);
    }
    else if(ch == ';'){
        printf("\n%c semicolon", ch);
    }
    else{
        flag++;
    }


}
/*
void comments(){
    bool isSingle = true;

    if(ch == '#'){
        int index = 0;
        pos = ftell(code);

        while(temp != '\n'){
           temp = fgetc(code);
           buffer[index] = temp;
           index++;
        }
        printf("%s singleComment", buffer);
    }
}

*/

void NKRwords(){

    if(ch == 'n'){
       pos = ftell(code);
       temp[0] = fgetc(code);

       if(temp[0] == 'u'){
         temp[1] = fgetc(code);
         if(temp[1] == 'm'){
            printf("\n%c%c%c int", ch,temp[0],temp[1]);
         }
       }
       else{
          printf("\n%c Lexeme not recognized.", ch);
          fseek(code,pos,SEEK_SET);
       }
    }
    else if(ch == 'b'){
       pos = ftell(code);
       temp[0] = fgetc(code);

       if(temp[0] == 'o'){
         temp[1] = fgetc(code);
         if(temp[1] == 'o'){
            temp[2] = fgetc(code);
            if(temp[2] == 'l'){
                temp[3] = fgetc(code);
                if(temp[3] == 'e'){
                    temp[4] = fgetc(code);
                    if(temp[4] == 'a'){
                        temp[5] = fgetc(code);
                        if(temp[5] == 'n'){
                            printf("\n%c%c%c%c%c%c%c bool", ch,temp[0],temp[1],temp[2],temp[3],temp[4],temp[5]);
                        }
                    }
                }
            }
         }
       }
       else{
          printf("\n%c Lexeme not recognized.", ch);
          fseek(code,pos,SEEK_SET);
       }
    }
    else if(ch == 'a'){
       pos = ftell(code);
       temp[0] = fgetc(code);

       if(temp[0] == 'n'){
         printf("\n%c%c noise", ch,temp[0]);
       }
       else{
          printf("\n%c Lexeme not recognized.", ch);
          fseek(code,pos,SEEK_SET);
       }
   }
   else if(ch == 'm'){
       pos = ftell(code);
       temp[0] = fgetc(code);

       if(temp[0] == 'a'){
         temp[1] = fgetc(code);
         if(temp[1] == 't'){
            temp[2] = fgetc(code);
            if(temp[2] == 'c'){
                temp[3] = fgetc(code);
                if(temp[3] == 'h'){
                    printf("\n%c%c%c%c%c match", ch,temp[0],temp[1],temp[2],temp[3]);
                }
            }
         }
       }
       else{
          printf("\n%c Lexeme not recognized.", ch);
          fseek(code,pos,SEEK_SET);
       }
    }
    else if(ch == 'c'){
       pos = ftell(code);
       temp[0] = fgetc(code);

       if(temp[0] == 'a'){
         temp[1] = fgetc(code);
         if(temp[1] == 's'){
            temp[2] = fgetc(code);
            if(temp[2] == 'e'){
                printf("\n%c%c%c%c case", ch,temp[0],temp[1],temp[2]);
            }
         }
       }
       else if(temp[0] == 'o'){
         temp[1] = fgetc(code);
         if(temp[1] == 'n'){
            temp[2] = fgetc(code);
            if(temp[2] == 't'){
                temp[3] = fgetc(code);
                if(temp[3] == 'i'){
                    temp[4] = fgetc(code);
                    if(temp[4] == 'n'){
                        temp[5] = fgetc(code);
                        if(temp[5] == 'u'){
                            temp[6] = fgetc(code);
                            if(temp[6] == 'e'){
                                printf("\n%c%c%c%c%c%c%c%c cont", ch,temp[0],temp[1],temp[2],temp[3],temp[4],temp[5], temp[6]);
                            }
                        }
                    }
                }
            }
         }
       }
       else{
          printf("\n%c Lexeme not recognized.", ch);
          fseek(code,pos,SEEK_SET);
       }
    }
    else if(ch == 'r'){
       pos = ftell(code);
       temp[0] = fgetc(code);

       if(temp[0] == 'e'){
         temp[1] = fgetc(code);
         if(temp[1] == 't'){
            temp[2] = fgetc(code);
            if(temp[2] == 'u'){
                temp[3] = fgetc(code);
                if(temp[3] == 'r'){
                    temp[4] = fgetc(code);
                    if(temp[4] == 'n'){
                        printf("\n%c%c%c%c%c%c return", ch,temp[0],temp[1],temp[2],temp[3],temp[4]);
                    }
                }
            }
         }
       }
       else{
          printf("\n%c Lexeme not recognized.", ch);
          fseek(code,pos,SEEK_SET);
       }
    }
    else if(ch == 'l'){
       pos = ftell(code);
       temp[0] = fgetc(code);

       if(temp[0] == 'i'){
         temp[1] = fgetc(code);
         if(temp[1] == 's'){
            temp[2] = fgetc(code);
            if(temp[2] == 't'){
                printf("\n%c%c%c%c list", ch,temp[0],temp[1],temp[2]);
            }
         }
       }
       else if(temp[0] == 'e'){
         temp[1] = fgetc(code);
         if(temp[1] == 't'){
            temp[2] = fgetc(code);
            if(temp[2] == 't'){
               temp[3] = fgetc(code);
                if(temp[3] == 'e'){
                    temp[4] = fgetc(code);
                    if(temp[4] == 'r'){
                        printf("\n%c%c%c%c%c%c char", ch,temp[0],temp[1],temp[2], temp[3], temp[4]);
                    }
                }
            }
         }
       }
       else{
          printf("\n%c Lexeme not recognized.", ch);
          fseek(code,pos,SEEK_SET);
       }
    }
    else if(ch == 'w'){
       pos = ftell(code);
       temp[0] = fgetc(code);

       if(temp[0] == 'o'){
         temp[1] = fgetc(code);
         if(temp[1] == 'r'){
            temp[2] = fgetc(code);
            if(temp[2] == 'd'){
                printf("\n%c%c%c%c string", ch,temp[0],temp[1],temp[2]);
            }
         }
       }
       else if(temp[0] == 'h'){
         temp[1] = fgetc(code);
         if(temp[1] == 'i'){
            temp[2] = fgetc(code);
            if(temp[2] == 'l'){
               temp[3] = fgetc(code);
                if(temp[3] == 'e'){
                    printf("\n%c%c%c%c%c while", ch,temp[0],temp[1],temp[2], temp[3]);
                }
            }
         }
       }
       else{
          printf("\n%c Lexeme not recognized.", ch);
          fseek(code,pos,SEEK_SET);
       }
    }
    else if(ch == 'f'){
       pos = ftell(code);
       temp[0] = fgetc(code);

       if(temp[0] == 'a'){
         temp[1] = fgetc(code);
         if(temp[1] == 'l'){
            temp[2] = fgetc(code);
            if(temp[2] == 's'){
                temp[3] = fgetc(code);
                if(temp[3] == 'e'){
                    printf("\n%c%c%c%c%c false", ch,temp[0],temp[1],temp[2], temp[3]);
                }
            }
         }
       }
       else if(temp[0] == 'o'){
         temp[1] = fgetc(code);
         if(temp[1] == 'r'){
            temp[2] = fgetc(code);
            if(temp[2] == 'e'){
                temp[3] = fgetc(code);
                if(temp[3] == 'a'){
                    temp[4] = fgetc(code);
                    if(temp[4] == 'c'){
                        temp[5] = fgetc(code);
                        if(temp[5] == 'h'){
                            printf("\n%c%c%c%c%c%c%c for", ch,temp[0],temp[1],temp[2],temp[3],temp[4],temp[5]);
                        }
                    }
                }
            }
         }
       }
       else{
          printf("\n%c Lexeme not recognized.", ch);
          fseek(code,pos,SEEK_SET);
       }
    }
    else if(ch == 'e'){
       pos = ftell(code);
       temp[0] = fgetc(code);

       if(temp[0] == 'n'){
         temp[1] = fgetc(code);
         if(temp[1] == 'd'){
             printf("\n%c%c%c end", ch,temp[0],temp[1]);
         }
       }
       else if(temp[0] == 'l'){
         temp[1] = fgetc(code);
         if(temp[1] == 's'){
            temp[2] = fgetc(code);
            if(temp[2] == 'e'){
                printf("\n%c%c%c%c else", ch,temp[0],temp[1],temp[2]);
            }
         }
       }
       else{
          printf("\n%c Lexeme not recognized.", ch);
          fseek(code,pos,SEEK_SET);
       }
    }
    else if(ch == 'i'){
       pos = ftell(code);
       temp[0] = fgetc(code);


       if(temp[0] == 'n'){
         temp[1] = fgetc(code);
         if(temp[1] == 'p'){
            temp[2] = fgetc(code);
            if(temp[2] == 'u'){
                temp[3] = fgetc(code);
                if(temp[3] == 't'){
                    printf("\n%c%c%c%c%c input", ch,temp[0],temp[1],temp[2],temp[3]);
                }
            }
         }
         else{
            printf("\n%c%c in", ch,temp[0]);
         }

       }
       else if(temp[0] == 'f'){
         printf("\n%c%c if", ch,temp[0]);
       }
       else{
          printf("\n%c Lexeme not recognized.", ch);
          fseek(code,pos,SEEK_SET);
       }
    }
    else if(ch == 't'){
       pos = ftell(code);
       temp[0] = fgetc(code);

       if(temp[0] == 'h'){
         temp[1] = fgetc(code);
         if(temp[1] == 'e'){
             temp[2] = fgetc(code);
             if(temp[2] == 'n'){
                printf("\n%c%c%c%c then", ch,temp[0],temp[1],temp[2]);
             }
             else{
                 printf("\n%c%c%c noise", ch,temp[0],temp[1]);
             }
}
       }
       else if(temp[0] == 'r'){
         temp[1] = fgetc(code);
         if(temp[1] == 'u'){
            temp[2] = fgetc(code);
            if(temp[2] == 'e'){
                printf("\n%c%c%c%c true", ch,temp[0],temp[1],temp[2]);
            }
         }
       }
       else{
          printf("\n%c Lexeme not recognized.", ch);
          fseek(code,pos,SEEK_SET);
       }
    }
    else if(ch == 'd'){
       pos = ftell(code);
       temp[0] = fgetc(code);

       if(temp[0] == 'o'){
         printf("\n%c%c do", ch,temp[0]);
       }
       else if(temp[0] == 'i'){
         temp[1] = fgetc(code);
         if(temp[1] == 's'){
            temp[2] = fgetc(code);
            if(temp[2] == 'p'){
                temp[3] = fgetc(code);
                if(temp[3] == 'l'){
                    temp[4] = fgetc(code);
                    if(temp[4] == 'a'){
                        temp[5] = fgetc(code);
                        if(temp[5] == 'y'){
                            printf("\n%c%c%c%c%c%c%c print", ch,temp[0],temp[1],temp[2],temp[3],temp[4],temp[5]);
                        }
                    }
                }
            }
         }
       }
       else if(temp[0] == 'e'){
         temp[1] = fgetc(code);
         if(temp[1] == 'c'){
            temp[2] = fgetc(code);
            if(temp[2] == 'i'){
                temp[3] = fgetc(code);
                if(temp[3] == 'm'){
                    temp[4] = fgetc(code);
                    if(temp[4] == 'a'){
                        temp[5] = fgetc(code);
                        if(temp[5] == 'l'){
                            printf("\n%c%c%c%c%c%c%c float", ch,temp[0],temp[1],temp[2],temp[3],temp[4],temp[5]);
                        }
                    }
                }
            }
         }
       }
       else{
          printf("\n%c Lexeme not recognized.", ch);
          fseek(code,pos,SEEK_SET);
       }
    }
    else{
        flag++;
    }

}


int main(){

    code = fopen("program.kidz", "r");
    if(code == NULL){
        printf("error.");
        exit(0);
    }
    do{
        ch = fgetc(code);
        //printf("%c", ch);

        operators();
        deli_bracks();
        NKRwords();
        //comments();
        //comments
        //noise word, keyword, reserved words
        //constant values
        //identifier

    }while(ch!=EOF);
    fclose(code);
    return 2;
}

