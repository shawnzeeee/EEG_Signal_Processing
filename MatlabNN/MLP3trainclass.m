%Define the Ytrain matrix : define which class this is

%Class0     % Nothing
%Class1     % Thumb open
%Class2     % Thumb close
%Class3     % Index open
%Class4     % Index close
%Class5     % Middle open
%Class6     % Middle close
%Class7     % Ring and pinky open
%Class8     % Ring and pinky close
%Class9     % Full hand open
%Class10    % Full hand close
Class = 12;
YClasses = categorical(Class, 0:12);