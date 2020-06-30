load('pendubot_record.mat')
record_data = record_data(2:end-1, record_data(end,:)==1 )
figure(1)
plot_order = [1,3,2,4]
for index = 1:4
    subplot(4,1,index);
    x = 1:size(record_data,2);
    y = record_data(plot_order(index),:);
    plot(x,y);
end

