function [Weigth, InfoKernel] = UnitTracevariableNumormalization(x, ...
                                    kernelTypeVec, kernelOptionVec, ...
                                    kernelVariableVec)
%

chunksize = 200;
variableNum = size(x, 1);
nbk = 1;
for i = 1:length(kernelTypeVec)
    % i
    for k = 1:length(kernelOptionVec{i})

        somme = 0;
        chunkNum = ceil(variableNum / chunksize);

        for chunkIndex = 1:chunkNum
            sampleVec = [(1 + (chunkIndex - 1) * chunksize) : ...
                         min(variableNum, chunkIndex * chunksize)];
            somme = somme + sum(diag(svmkernel(...
                        x(sampleVec, kernelVariableVec{i}), kernelTypeVec{i},...
                        kernelOptionVec{i}(k))));
        end

        if somme ~= 0
            Weigth(nbk) = 1 / somme;
            InfoKernel(nbk).kernel = kernelTypeVec{i};
            InfoKernel(nbk).kerneloption = kernelOptionVec{i}(k);
            InfoKernel(nbk).variable = kernelVariableVec{i};
            InfoKernel(nbk).Weigth = 1 / somme;
            nbk = nbk + 1;
        end
    end
end
