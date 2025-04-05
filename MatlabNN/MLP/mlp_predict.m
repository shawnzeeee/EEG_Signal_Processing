function y = mlp_predict(x)
    persistent net
    if isempty(net)
        data = load('MLP1.0.0.mat');
        net = data.net;  % or whatever variable name you saved it as
    end
    y = net(x);  % or y = predict(net, x) depending on network type
end
