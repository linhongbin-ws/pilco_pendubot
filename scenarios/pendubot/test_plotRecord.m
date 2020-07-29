global RecordCell 

if ~isempty(RecordCell{1})
    figure(1);

    for i = 1:6
        ax = subplot(3,2,i);
        plot(ax, RecordCell{end}, RecordCell{i});

%                   legend(legendList(i))
%                     if isInitPlot
%                         hold(ax, 'on')
%                         legend(legendList(i))
%                         hold(ax, 'off')
%                         isInitPlot = false
%                     end
    end
    drawnow
end