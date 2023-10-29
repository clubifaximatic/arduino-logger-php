<?php
require_once PROJECT_ROOT_PATH . "/model/database.php";
class SampleModel extends Database
{
    public function list($sample, $limit)
    {
        return $this->select("SELECT created_at, data, sample FROM samples WHERE sample = ? ORDER BY created_at DESC LIMIT ?", ["ii", $sample, $limit]);
    }

    public function get($sample, $since, $until, $groupMinutes = 0)
    {
        if ($groupMinutes > 0) {
            return $this->select(
                "SELECT created_at, data, sample FROM samples WHERE sample = ? AND created_at BETWEEN ? AND ? GROUP BY UNIX_TIMESTAMP(created_at) div (?) ORDER BY created_at ASC",
                ["iss", $sample, $since, $until], groupMinutes * 60);
        }

        return $this->select("SELECT created_at, data, sample FROM samples WHERE sample = ? AND created_at BETWEEN ? AND ? ORDER BY created_at ASC", ["iss", $sample, $since, $until]);
    }    
    
    public function set($sample, $data)
    {
        $timestamp = date('Y-m-d H:i:s');
        return $this->insert("INSERT INTO samples (created_at, data) VALUES (?,?,?)", ["ssi", $timestamp, $data, $sample]);
    }
}