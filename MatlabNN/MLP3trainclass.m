%Define the Ytrain matrix : define which class this is

%Class0    % Nothing
%Class1     % Thumb open
%Class2     % Thumb close
%Class3     % Index open
%Class4     % Index close
%Class5     % Middle open
%Class6     % Middle close
%Class7     % Ring open
%Class8     % Ring close
%Class9     % Pinky open
%Class10     % Pinky close
%Class11    % Full hand open
%Class12    % Full hand close
Class = 12;
YClasses = categorical(Class, 0:12);