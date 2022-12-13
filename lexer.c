#include<stdio.h>


    int i = 0;
    char buffer[1000];
    int pos;
    char ch;
    FILE *code;
    char line[100];
    char temp[];
    int flag = 0;
    int NKRflag = 0;

void operators(){

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


void comments(){

    if(ch == '#'){

        pos = ftell(code);

        printf("\n%c", ch);

        for(int i=0;temp[i]!='\n';i++){
           temp[i] = fgetc(code);
        }
        printf("%s singleComment", temp);
    }
}


void NKRwords(){

    if(ch == 'n'){
       pos = ftell(code);
       temp[0] = fgetc(code);

       if(temp[0] == 'u'){
         temp[1] = fgetc(code);

         if(temp[1] == 'm'){
            printf("\n%c%c%c int", ch,temp[0],temp[1]);
         }
         else{
          fseek(code,pos,SEEK_SET);
          identifier();
         }

       }
       else{
          fseek(code,pos,SEEK_SET);
          identifier();
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
                        else{
                          fseek(code,pos,SEEK_SET);
                          identifier();
                         }
                    }
                    else{
                      fseek(code,pos,SEEK_SET);
                      identifier();
                    }
                }
                else{
                  fseek(code,pos,SEEK_SET);
                  identifier();
                 }
            }
            else{
              fseek(code,pos,SEEK_SET);
              identifier();
             }
         }
         else{
          fseek(code,pos,SEEK_SET);
          identifier();
         }
       }
       else{
          fseek(code,pos,SEEK_SET);
          identifier();
       }
    }
    else if(ch == 'a'){
       pos = ftell(code);
       temp[0] = fgetc(code);

       if(temp[0] == 'n'){
         printf("\n%c%c noise", ch,temp[0]);
       }
       else{
          fseek(code,pos,SEEK_SET);
          identifier();
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
                else{
                  fseek(code,pos,SEEK_SET);
                  identifier();
               }
            }
            else{
              fseek(code,pos,SEEK_SET);
              identifier();
            }
         }
         else{
          fseek(code,pos,SEEK_SET);
          identifier();
        }
       }
       else{
          fseek(code,pos,SEEK_SET);
          identifier();
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
            else{
              fseek(code,pos,SEEK_SET);
              identifier();
             }

         }
         else{
          fseek(code,pos,SEEK_SET);
          identifier();
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
                              else{
                                  fseek(code,pos,SEEK_SET);
                                  identifier();
                                }
                        }
                        else{
                          fseek(code,pos,SEEK_SET);
                          identifier();
                         }
                    }
                    else{
                      fseek(code,pos,SEEK_SET);
                      identifier();
                     }
                }
                else{
                  fseek(code,pos,SEEK_SET);
                  identifier();
                 }
            }
            else{
              fseek(code,pos,SEEK_SET);
              identifier();
             }
         }
         else{
          fseek(code,pos,SEEK_SET);
          identifier();
         }
       }
       else{
          fseek(code,pos,SEEK_SET);
          identifier();
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
                    else{
                      fseek(code,pos,SEEK_SET);
                      identifier();
                     }
                }
                else{
                  fseek(code,pos,SEEK_SET);
                  identifier();
                 }
            }
            else{
              fseek(code,pos,SEEK_SET);
              identifier();
             }
         }
         else{
          fseek(code,pos,SEEK_SET);
          identifier();
         }
       }
       else{
          fseek(code,pos,SEEK_SET);
          identifier();
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
            else{
              fseek(code,pos,SEEK_SET);
              identifier();
             }
         }
         else{
          fseek(code,pos,SEEK_SET);
          identifier();
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
                    else{
                      fseek(code,pos,SEEK_SET);
                      identifier();
                     }
                }
                else{
                  fseek(code,pos,SEEK_SET);
                  identifier();
                 }
            }
            else{
              fseek(code,pos,SEEK_SET);
              identifier();
             }
         }
         else{
          fseek(code,pos,SEEK_SET);
          identifier();
         }
       }
       else{
          fseek(code,pos,SEEK_SET);
          identifier();
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
            else{
              fseek(code,pos,SEEK_SET);
              identifier();
             }
         }
         else{
          fseek(code,pos,SEEK_SET);
          identifier();
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
                else{
                  fseek(code,pos,SEEK_SET);
                  identifier();
                 }
            }
            else{
              fseek(code,pos,SEEK_SET);
              identifier();
             }
         }
         else{
          fseek(code,pos,SEEK_SET);
          identifier();
         }
       }
       else{
          fseek(code,pos,SEEK_SET);
          identifier();
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
                else{
                  fseek(code,pos,SEEK_SET);
                  identifier();
                 }
            }
            else{
              fseek(code,pos,SEEK_SET);
              identifier();
             }
         }
         else{
          fseek(code,pos,SEEK_SET);
          identifier();
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
                        else{
                          fseek(code,pos,SEEK_SET);
                          identifier();
                         }
                    }
                    else{
                      fseek(code,pos,SEEK_SET);
                      identifier();
                     }
                }
                else{
                  fseek(code,pos,SEEK_SET);
                  identifier();
                 }
            }
            else{
              fseek(code,pos,SEEK_SET);
              identifier();
             }
         }
         else{
          fseek(code,pos,SEEK_SET);
          identifier();
         }
       }
       else{
          fseek(code,pos,SEEK_SET);
          identifier();
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
         else{
          fseek(code,pos,SEEK_SET);
          identifier();
         }
       }
       else if(temp[0] == 'l'){
         temp[1] = fgetc(code);
         if(temp[1] == 's'){
            temp[2] = fgetc(code);
            if(temp[2] == 'e'){
                printf("\n%c%c%c%c else", ch,temp[0],temp[1],temp[2]);
            }
            else{
              fseek(code,pos,SEEK_SET);
              identifier();
             }
         }
         else{
          fseek(code,pos,SEEK_SET);
          identifier();
         }
       }
       else{
          fseek(code,pos,SEEK_SET);
          identifier();
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
                else{
                  fseek(code,pos,SEEK_SET);
                  identifier();
                 }
            }
            else{
              fseek(code,pos,SEEK_SET);
              identifier();
             }
         }
         else if(temp[1]==' '){
            printf("\n%c%c in", ch,temp[0]);
         }
         else{
          fseek(code,pos,SEEK_SET);
          identifier();
         }

       }
       else if(temp[0] == 'f'){
         printf("\n%c%c if", ch,temp[0]);
       }
       else{
          fseek(code,pos,SEEK_SET);
          identifier();
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
             else if(temp[2]==' '){
                 printf("\n%c%c%c noise", ch,temp[0],temp[1]);
             }
             else{
              fseek(code,pos,SEEK_SET);
              identifier();
             }
        }
        else{
          fseek(code,pos,SEEK_SET);
          identifier();
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
          fseek(code,pos,SEEK_SET);
          identifier();
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
                        else{
                          fseek(code,pos,SEEK_SET);
                          identifier();
                         }
                    }
                    else{
                      fseek(code,pos,SEEK_SET);
                      identifier();
                     }
                }
                else{
                  fseek(code,pos,SEEK_SET);
                  identifier();
                 }
            }
            else{
              fseek(code,pos,SEEK_SET);
              identifier();
             }
         }
         else{
          fseek(code,pos,SEEK_SET);
          identifier();
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
                        else{
                          fseek(code,pos,SEEK_SET);
                          identifier();
                         }
                    }
                    else{
                      fseek(code,pos,SEEK_SET);
                      identifier();
                     }
                }
                else{
                  fseek(code,pos,SEEK_SET);
                  identifier();
                 }
            }
            else{
              fseek(code,pos,SEEK_SET);
              identifier();
            }
         }
         else{
          fseek(code,pos,SEEK_SET);
          identifier();
         }
       }
       else{
          fseek(code,pos,SEEK_SET);
          identifier();
       }
    }
    else{
        identifier();
    }

}


void identifier(){
    int i =0;
    char tempID[31];
    if((ch>='a' && ch<='z') || (ch>='A' && ch<='Z')){
        pos = ftell(code);
        temp[0] = fgetc(code);

        if( (temp[0]>='a' && temp[0]<='z') || (temp[0]>='A' && temp[0]<='Z') || (temp[0]>='0' && temp[0]<='9') || temp[0]=='_'){
            pos = ftell(code);
            temp[1] = fgetc(code);

            if((temp[1]>='a' && temp[1]<='z') || (temp[1]>='A' && temp[1]<='Z') || (temp[1]>='0' && temp[1]<='9') || temp[1]=='_'){

            pos = ftell(code);
            temp[2] = fgetc(code);

            if((temp[2]>='a' && temp[2]<='z') || (temp[2]>='A' && temp[2]<='Z') || (temp[2]>='0' && temp[2]<='9') || temp[2]=='_'){

            pos = ftell(code);
            temp[3] = fgetc(code);

            if((temp[3]>='a' && temp[3]<='z') || (temp[3]>='A' && temp[3]<='Z') || (temp[3]>='0' && temp[3]<='9') || temp[3]=='_'){
            pos = ftell(code);
            temp[4] = fgetc(code);

            if((temp[4]>='a' && temp[4]<='z') || (temp[4]>='A' && temp[4]<='Z') || (temp[4]>='0' && temp[4]<='9') || temp[4]=='_'){
            pos = ftell(code);
            temp[5] = fgetc(code);

            if((temp[5]>='a' && temp[5]<='z') || (temp[5]>='A' && temp[5]<='Z') || (temp[5]>='0' && temp[5]<='9') || temp[5]=='_'){
            pos = ftell(code);
            temp[6] = fgetc(code);

            if((temp[6]>='a' && temp[6]<='z') || (temp[6]>='A' && temp[6]<='Z') || (temp[6]>='0' && temp[6]<='9') || temp[6]=='_'){
            pos = ftell(code);
            temp[7] = fgetc(code);

            if((temp[7]>='a' && temp[7]<='z') || (temp[7]>='A' && temp[7]<='Z') || (temp[7]>='0' && temp[7]<='9') || temp[7]=='_'){
            pos = ftell(code);
            temp[8] = fgetc(code);

            if((temp[8]>='a' && temp[8]<='z') || (temp[8]>='A' && temp[8]<='Z') || (temp[8]>='0' && temp[8]<='9') || temp[8]=='_'){
            pos = ftell(code);
            temp[9] = fgetc(code);

            if((temp[9]>='a' && temp[9]<='z') || (temp[9]>='A' && temp[9]<='Z') || (temp[9]>='0' && temp[9]<='9') || temp[9]=='_'){
            pos = ftell(code);
            temp[10] = fgetc(code);

            if((temp[10]>='a' && temp[10]<='z') || (temp[10]>='A' && temp[10]<='Z') || (temp[10]>='0' && temp[10]<='9') || temp[10]=='_'){
            pos = ftell(code);
            temp[11] = fgetc(code);

            if((temp[11]>='a' && temp[11]<='z') || (temp[11]>='A' && temp[11]<='Z') || (temp[11]>='0' && temp[11]<='9') || temp[11]=='_'){
            pos = ftell(code);
            temp[12] = fgetc(code);

            if((temp[12]>='a' && temp[12]<='z') || (temp[12]>='A' && temp[12]<='Z') || (temp[12]>='0' && temp[12]<='9') || temp[12]=='_'){
            pos = ftell(code);
            temp[13] = fgetc(code);

            if((temp[13]>='a' && temp[13]<='z') || (temp[13]>='A' && temp[13]<='Z') || (temp[13]>='0' && temp[13]<='9') || temp[13]=='_'){
            pos = ftell(code);
            temp[14] = fgetc(code);

            if((temp[14]>='a' && temp[14]<='z') || (temp[14]>='A' && temp[14]<='Z') || (temp[14]>='0' && temp[14]<='9') || temp[14]=='_'){
            pos = ftell(code);
            temp[15] = fgetc(code);

            if((temp[15]>='a' && temp[15]<='z') || (temp[15]>='A' && temp[15]<='Z') || (temp[15]>='0' && temp[15]<='9') || temp[15]=='_'){
            pos = ftell(code);
            temp[16] = fgetc(code);

            if((temp[16]>='a' && temp[16]<='z') || (temp[16]>='A' && temp[16]<='Z') || (temp[16]>='0' && temp[16]<='9') || temp[16]=='_'){
            pos = ftell(code);
            temp[17] = fgetc(code);

            if((temp[17]>='a' && temp[17]<='z') || (temp[17]>='A' && temp[17]<='Z') || (temp[17]>='0' && temp[17]<='9') || temp[17]=='_'){
            pos = ftell(code);
            temp[18] = fgetc(code);

            if((temp[18]>='a' && temp[18]<='z') || (temp[18]>='A' && temp[18]<='Z') || (temp[18]>='0' && temp[18]<='9') || temp[18]=='_'){
            pos = ftell(code);
            temp[19] = fgetc(code);

            if((temp[19]>='a' && temp[19]<='z') || (temp[19]>='A' && temp[19]<='Z') || (temp[19]>='0' && temp[19]<='9') || temp[19]=='_'){
            pos = ftell(code);
            temp[20] = fgetc(code);

            if((temp[20]>='a' && temp[20]<='z') || (temp[20]>='A' && temp[20]<='Z') || (temp[20]>='0' && temp[20]<='9') || temp[20]=='_'){
            pos = ftell(code);
            temp[21] = fgetc(code);

            if((temp[21]>='a' && temp[21]<='z') || (temp[21]>='A' && temp[21]<='Z') || (temp[21]>='0' && temp[21]<='9') || temp[21]=='_'){
            pos = ftell(code);
            temp[22] = fgetc(code);

            if((temp[22]>='a' && temp[22]<='z') || (temp[22]>='A' && temp[22]<='Z') || (temp[22]>='0' && temp[22]<='9') || temp[22]=='_'){
            pos = ftell(code);
            temp[23] = fgetc(code);

            if((temp[23]>='a' && temp[23]<='z') || (temp[23]>='A' && temp[23]<='Z') || (temp[23]>='0' && temp[23]<='9') || temp[23]=='_'){
            pos = ftell(code);
            temp[24] = fgetc(code);

            if((temp[24]>='a' && temp[24]<='z') || (temp[24]>='A' && temp[22]<='Z') || (temp[22]>='0' && temp[22]<='9') || temp[22]=='_'){

            }
            else{
                fseek(code,pos,SEEK_SET);
                printf("\n%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c id", ch,temp[0],temp[1],temp[2],temp[3],temp[4],temp[5],temp[6],temp[7],temp[8],temp[9],temp[10],temp[11],temp[12],temp[13],temp[14],temp[16],temp[17],temp[18],temp[19],temp[20],temp[21],temp[22]);
            }
            }
            else{
                fseek(code,pos,SEEK_SET);
                printf("\n%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c id", ch,temp[0],temp[1],temp[2],temp[3],temp[4],temp[5],temp[6],temp[7],temp[8],temp[9],temp[10],temp[11],temp[12],temp[13],temp[14],temp[16],temp[17],temp[18],temp[19],temp[20],temp[21],temp[22]);
            }
            }
            else{
                fseek(code,pos,SEEK_SET);
                printf("\n%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c id", ch,temp[0],temp[1],temp[2],temp[3],temp[4],temp[5],temp[6],temp[7],temp[8],temp[9],temp[10],temp[11],temp[12],temp[13],temp[14],temp[16],temp[17],temp[18],temp[19],temp[20],temp[21],temp[22]);
            }
            }
            else{
                fseek(code,pos,SEEK_SET);
                printf("\n%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c id", ch,temp[0],temp[1],temp[2],temp[3],temp[4],temp[5],temp[6],temp[7],temp[8],temp[9],temp[10],temp[11],temp[12],temp[13],temp[14],temp[16],temp[17],temp[18],temp[19],temp[20],temp[21]);
            }
            }
            else{
                fseek(code,pos,SEEK_SET);
                printf("\n%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c id", ch,temp[0],temp[1],temp[2],temp[3],temp[4],temp[5],temp[6],temp[7],temp[8],temp[9],temp[10],temp[11],temp[12],temp[13],temp[14],temp[16],temp[17],temp[18],temp[19],temp[20]);
            }
            else{
                fseek(code,pos,SEEK_SET);
                printf("\n%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c id", ch,temp[0],temp[1],temp[2],temp[3],temp[4],temp[5],temp[6],temp[7],temp[8],temp[9],temp[10],temp[11],temp[12],temp[13],temp[14],temp[16],temp[17],temp[18],temp[19]);
            }
            }
            else{
                fseek(code,pos,SEEK_SET);
                printf("\n%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c id", ch,temp[0],temp[1],temp[2],temp[3],temp[4],temp[5],temp[6],temp[7],temp[8],temp[9],temp[10],temp[11],temp[12],temp[13],temp[14],temp[16],temp[17],temp[18]);
            }
            }
            else{
                fseek(code,pos,SEEK_SET);
                printf("\n%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c id", ch,temp[0],temp[1],temp[2],temp[3],temp[4],temp[5],temp[6],temp[7],temp[8],temp[9],temp[10],temp[11],temp[12],temp[13],temp[14],temp[16],temp[17]);
            }
            }
            else{
                fseek(code,pos,SEEK_SET);
                printf("\n%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c id", ch,temp[0],temp[1],temp[2],temp[3],temp[4],temp[5],temp[6],temp[7],temp[8],temp[9],temp[10],temp[11],temp[12],temp[13],temp[14],temp[16]);
            }
            }
            else{
                fseek(code,pos,SEEK_SET);
                printf("\n%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c id", ch,temp[0],temp[1],temp[2],temp[3],temp[4],temp[5],temp[6],temp[7],temp[8],temp[9],temp[10],temp[11],temp[12],temp[13],temp[14]);
            }
            }
            else{
                fseek(code,pos,SEEK_SET);
                printf("\n%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c id", ch,temp[0],temp[1],temp[2],temp[3],temp[4],temp[5],temp[6],temp[7],temp[8],temp[9],temp[10],temp[11],temp[12],temp[13]);
            }
            }
            else{
                fseek(code,pos,SEEK_SET);
                printf("\n%c%c%c%c%c%c%c%c%c%c%c%c%c%c id", ch,temp[0],temp[1],temp[2],temp[3],temp[4],temp[5],temp[6],temp[7],temp[8],temp[9],temp[10],temp[11],temp[12]);
            }
            }
            else{
                fseek(code,pos,SEEK_SET);
                printf("\n%c%c%c%c%c%c%c%c%c%c%c%c%c id", ch,temp[0],temp[1],temp[2],temp[3],temp[4],temp[5],temp[6],temp[7],temp[8],temp[9],temp[10],temp[11]);
            }
            }
            else{
                fseek(code,pos,SEEK_SET);
                printf("\n%c%c%c%c%c%c%c%c%c%c%c%c id", ch,temp[0],temp[1],temp[2],temp[3],temp[4],temp[5],temp[6],temp[7],temp[8],temp[9],temp[10]);
            }
            }
            else{
                fseek(code,pos,SEEK_SET);
                printf("\n%c%c%c%c%c%c%c%c%c%c%c id", ch,temp[0],temp[1],temp[2],temp[3],temp[4],temp[5],temp[6],temp[7],temp[8],temp[9]);
            }
            }
            else{
                fseek(code,pos,SEEK_SET);
                printf("\n%c%c%c%c%c%c%c%c%c%c id", ch,temp[0],temp[1],temp[2],temp[3],temp[4],temp[5],temp[6],temp[7],temp[8]);
            }
            }
            else{
                fseek(code,pos,SEEK_SET);
                printf("\n%c%c%c%c%c%c%c%c%c id", ch,temp[0],temp[1],temp[2],temp[3],temp[4],temp[5],temp[6],temp[7]);
            }
            }
            else{
                fseek(code,pos,SEEK_SET);
                printf("\n%c%c%c%c%c%c%c%c id", ch,temp[0],temp[1],temp[2],temp[3],temp[4],temp[5],temp[6]);
            }
            }
            else{
                fseek(code,pos,SEEK_SET);
                printf("\n%c%c%c%c%c%c%c id", ch,temp[0],temp[1],temp[2],temp[3],temp[4],temp[5]);
            }
            }
            else{
                fseek(code,pos,SEEK_SET);
                printf("\n%c%c%c%c%c%c id", ch,temp[0],temp[1],temp[2],temp[3],temp[4]);
            }
            }
            else{
                fseek(code,pos,SEEK_SET);
                printf("\n%c%c%c%c%c id", ch,temp[0],temp[1],temp[2],temp[3]);
            }
            }
            else{
                fseek(code,pos,SEEK_SET);
                printf("\n%c%c%c%c id", ch,temp[0],temp[1],temp[2]);
            }
            }
            else{
                fseek(code,pos,SEEK_SET);
                printf("\n%c%c%c id", ch,temp[0],temp[1]);
            }
            }
            else{
                fseek(code,pos,SEEK_SET);
                printf("\n%c%c id", ch,temp[0]);
            }
        }
        else{
            printf("\n%c id", ch);
            fseek(code,pos,SEEK_SET);
        }
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

        operators();
        deli_bracks();
        //comments();
        NKRwords(); //calls the identifier function inside
        //constant values


    }while(ch!=EOF);
    fclose(code);
    return 2;
}

