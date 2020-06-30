function undefinedVars = findUndefinedVars(modelName)
    undefinedVars = [];
    stillErrors = 1;
    while stillErrors
        try
            Simulink.findVars(modelName);
            stillErrors = 0;
        catch err
            % If the error is an undefined block parameter then find the name and add it to the list
            cause = err.cause;
            if ~isempty(cause) && strcmp(cause{1}.identifier,'Simulink:Parameters:BlkParamUndefined')
                varName = regexp(cause{1}.message,'variable ''(\w+)''','tokens');
                if ~isempty(varName)
                    undefinedVars = [undefinedVars varName{1}];
                    evalin('base',[varName{1}{1},'=0;']);
                end
                % Display any other errors as usual.
            else
                stillErrors = 0;
                rethrow(err);
            end
        end
    end