// SPDX-License-Identifier: GPL-3.0
pragma solidity >=0.7.0 <0.9.0;

contract CrowdFunding {
    address public manager;
    uint256 minimumContribution;
    mapping(address => uint256) contributions;
    uint256 deadline;
    uint256 public target;
    uint256 risedFunds;
    uint256 public noOfContributors;

    struct Request {
        string description;
        address payable recipent;
        uint256 value;
        bool completed;
        uint256 noOfVoters;
        mapping(address => bool) voters;
    }

    mapping(uint256 => Request) requests;

    uint256 numOfRequest;

    constructor(
        uint256 _minimumCon,
        uint256 _deadline,
        uint256 _target
    ) {
        minimumContribution = _minimumCon;
        deadline = block.timestamp + _deadline;
        target = _target;
        manager = msg.sender;
    }

    function sendEth() public payable {
        require(
            msg.value >= minimumContribution,
            "Minimum cintribution must be 100."
        );
        require(block.timestamp < deadline, "The deadline has been passed.");

        if (contributions[msg.sender] == 0) {
            noOfContributors++;
        }

        contributions[msg.sender] += msg.value;
        risedFunds += msg.value;
    }

    function getContractBalance() public view returns (uint256) {
        return address(this).balance;
    }

    function refund() public {
        require(
            block.timestamp > deadline && risedFunds < target,
            "You are not eigable for refund."
        );
        require(contributions[msg.sender] > 0, "0 funded");
        address payable user = payable(msg.sender);
        user.transfer(contributions[msg.sender]);
        contributions[msg.sender] = 0;
    }

    modifier onlyManager() {
        require(msg.sender == manager, "Only manager can create request");
        _;
    }

    function createRequest(
        string memory _description,
        address payable _recipent,
        uint256 _value
    ) public onlyManager {
        Request storage newRequest = requests[numOfRequest];
        numOfRequest++;
        newRequest.description = _description;
        newRequest.recipent = _recipent;
        newRequest.value = _value;
        newRequest.completed = false;
        newRequest.noOfVoters = 0;
    }

    function voteRequest(uint256 _requestNo) public {
        require(contributions[msg.sender] > 0, " You must be a contributor.");
        Request storage thisRequest = requests[_requestNo];
        require(thisRequest.voters[msg.sender] == false, " You already voted.");
        thisRequest.voters[msg.sender] = true;
        thisRequest.noOfVoters++;
    }

    function makePayment(uint256 _reqNo) public onlyManager {
        require(risedFunds >= target, " Target did not reached.");
        Request storage thisRequest = requests[_reqNo];
        require(
            thisRequest.completed == false,
            " This request already completed"
        );
        require(
            thisRequest.noOfVoters > noOfContributors / 2,
            "Majority did not support."
        );
        thisRequest.recipent.transfer(thisRequest.value);
        thisRequest.completed = true;
    }
}
